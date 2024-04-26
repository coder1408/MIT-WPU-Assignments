class Subnet:
    def __init__(self,ip,subnets):
        self.ip = ip
        self.subnets = subnets
        self.ip_array=[int(x) for x in self.ip.split('.')]

    def ip_class(self):
        if self.ip_array[0] < 128:
            print("Class A")
        elif self.ip_array[0] <191:
            print("Class B")
        elif self.ip_array[0]< 223:
            print("Class C")
        elif self.ip_array[0] <239:
            print("Class D")
        elif self.ip_array[0] <255:
            print("Class E")
        else:
            print("Invalid IP")
    
    def ip_size(self):
        if self.ip_array[0] < 128:
            size=256*256*256
        elif self.ip_array[0] <191:
            size=256*256
        elif self.ip_array[0]< 223:
            size=256
        print("Size of IP is: ",size)
           
    def default_subnet(self):
        if self.ip_array[0] < 128:
            print("Subnet: 255.0.0.0")
        elif self.ip_array[0] <191:
            print("Subnet: 255.255.0.0")
        elif self.ip_array[0]< 223:
            print("Subnet: 255.255.255.0")
        else:
            print("Invalid IP")
    def new_subnet_mask(self,subnets):
        if self.ip_array[0] < 128:
            subnet_size=266 - (256 // subnets)
            print(f"New Subnet Mask: 255.{subnet_size}.0.0")
        elif self.ip_array[0] <191:
            subnet_size=266 - (256 // subnets)
            print(f"New Subnet Mask: 255.255.{subnet_size}.0")  
        elif self.ip_array[0] <223:
            subnet_size=266 - (256 // subnets)
            print(f"New Subnet Mask : 255.255.255.{subnet_size}")
        else:
            print("Invalid IP")


    def print_ips(self):
        subnet_size=256 // self.subnets
        for i in range(self.subnets):
            start_ip=i*subnet_size
            end_ip  =(i+1)*subnet_size -1
            print(f"Subnet {i+1} IP RANGE: {self.ip_array[0]}.{self.ip_array[1]}.{self.ip_array[2]}.{start_ip} - {self.ip_array[0]}.{self.ip_array[1]}.{self.ip_array[2]}.{end_ip}")

ip = input("Enter IP: ")
subnets = int(input("Enter number of subnets: "))
subnet=Subnet(ip,subnets)
subnet.ip_class()
subnet.new_subnet_mask(subnets)
subnet.ip_size()
subnet.default_subnet()
subnet.print_ips()
