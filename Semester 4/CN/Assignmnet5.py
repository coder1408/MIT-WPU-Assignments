import ipaddress

def get_ip_class(ip_address):
    """Determines the class of the given IP address (A, B, C, D, or E)."""
    first_octet = int(ip_address) >> 24  # Extract the first octet using bitwise shift
    if 0 <= first_octet <= 127:
        return 'A'
    elif 128 <= first_octet <= 191:
        return 'B'
    elif 192 <= first_octet <= 223:
        return 'C'
    elif 224 <= first_octet <= 239:
        return 'D'
    else:
        return 'E'

def get_default_subnet_mask(ip_class):
    """Returns the default subnet mask for the given IP class."""
    if ip_class == 'A':
        return '255.0.0.0'
    elif ip_class == 'B':
        return '255.255.0.0'
    elif ip_class == 'C':
        return '255.255.255.0'
    else:
        return None  # Handle D and E classes appropriately (limited subnetting)

def calculate_subnet_mask(cidr_notation, ip_class):
    """Calculates the subnet mask based on CIDR notation or uses the default mask for the IP class."""
    cidr_parts = cidr_notation.strip().split('/')
    if len(cidr_parts) == 2:
        prefixlen = int(cidr_parts[1])
        return ipaddress.netmask(prefixlen=prefixlen).exploded
    else:
        return get_default_subnet_mask(ip_class)

def calculate_usable_hosts(prefixlen):
    """Calculates the number of usable hosts in a subnet based on CIDR prefix length."""
    return 2 ** (32 - prefixlen) - 2  # Subtract 2 for network and broadcast addresses

def subnet_calculator():
    """Performs subnetting calculations and displays results."""
    while True:
        ip_address = input("Enter IP address (or CIDR notation): ")
        try:
            network = ipaddress.ip_interface(ip_address)
            break
        except ValueError:
            print("Invalid IP address or CIDR notation. Please try again.")

    num_subnets = int(input("Enter the number of subnets to be formed: "))

    ip_class = get_ip_class(network.ip)
    default_subnet_mask = get_default_subnet_mask(ip_class)

    # Handle CIDR notation input or calculate CIDR from default mask (for future enhancements)
    cidr_notation = network.netmask.exploded
    new_subnet_mask = calculate_subnet_mask(cidr_notation, ip_class)

    print(f"\nClass of IP: {ip_class}")
    print(f"Default subnet mask: {default_subnet_mask}")

    # Calculate required bits to borrow for the desired number of subnets
    bits_to_borrow = int(len(bin(num_subnets - 1)[2:]))

    # Calculate new prefix length based on CIDR and borrowed bits
    new_prefixlen = network.network.prefixlen + bits_to_borrow
    if new_prefixlen > 32:
        print("Error: The requested number of subnets cannot be created with the given IP address.")
        return

    usable_hosts_per_subnet = calculate_usable_hosts(new_prefixlen)

    print(f"\nNew subnet mask: {new_subnet_mask}")
    print(f"Usable hosts per subnet: {usable_hosts_per_subnet}")

    # Iterate through each subnet and calculate network address, broadcast address, and IP range
    for i in range(num_subnets):
        subnet_network = network.network.network_address + i * (2 ** (32 - new_prefixlen))
        subnet_broadcast = subnet_network + (2 ** (32 - new_prefixlen)) - 1
        first_usable_ip = subnet_network + 1
        last_usable_ip = subnet_broadcast - 1

        print(f"\nSubnet {i + 1}:")
        print(f"  Network address: {subnet_network}")
        print(f"  Broadcast address: {subnet_broadcast}")
        print(f"  IP range: {first_usable_ip} - {last_usable_ip}")

    # Prompt the user to choose an option
    while True:
        option = input("\nDo you want to calculate another subnet? (Y/N): ")
        if option.upper() == 'Y':
            subnet_calculator()
        elif option.upper() == 'N':
            print("Exiting subnet calculator.")
            break
        else:
            print("Invalid option. Please try again.")

if __name__ == "__main__":
    subnet_calculator()
