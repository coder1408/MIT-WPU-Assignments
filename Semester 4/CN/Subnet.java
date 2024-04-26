import java.util.Scanner;

public class Subnet {

	String iPAddress;
	int n;
	int[] ip_array;

	public Subnet(String iPAddress, int n) {
		this.iPAddress = iPAddress;
		this.n = n;

		ip_array = new int[4];
		String[] ip = iPAddress.split("[.]");
		for (int i = 0; i < 4; i++) {
			ip_array[i] = Integer.parseInt(ip[i]);
		}
	}

	public void printSize() {

		if (ip_array[0] <= 126)
			System.out.println("Size of Subnet : " + (256 * 256 * 256 / n));
		else if (ip_array[0] <= 191)
			System.out.println("Size of Subnet : " + (256 * 256 / n));
		else
			System.out.println("Size of Subnet : " + (256 / n));
	}

	public void printClass() {
		if (ip_array[0] <= 126)
			System.out.println("IP Class : A");
		else if (ip_array[0] <= 191)
			System.out.println("IP Class : B");
		else if (ip_array[0] <= 223)
			System.out.println("IP Class : C");
		else if (ip_array[0] <= 239)
			System.out.println("IP Class : D");
		else if (ip_array[0] <= 254)
			System.out.println("IP Class : E");
		else
			System.out.println("Invalid IP : No Class");
	}

	public void printSubnetMask() {

		int a1 = 0, a2 = 0, a3 = 0;

		if (ip_array[0] <= 126) {
			if (n < 2)
				a1 = 128;
			else if (n < 4)
				a1 = 128 + 64;
			else if (n < 8)
				a1 = 128 + 64 + 32;
			else if (n < 16)
				a1 = 128 + 64 + 32 + 16;
			else if (n < 32)
				a1 = 128 + 64 + 32 + 16 + 8;
			else if (n < 64)
				a1 = 128 + 64 + 32 + 16 + 8 + 4;
			else if (n < 128)
				a1 = 128 + 64 + 32 + 16 + 8 + 4 + 2;
			else if (n < 256) {
				a1 = 255;
				a2 = 128;
			} else if (n < 512) {
				a1 = 255;
				a2 = 128 + 64;
			} else if (n < 1024) {
				a1 = 255;
				a2 = 128 + 64 + 32;
			} else if (n < 2048) {
				a1 = 255;
				a2 = 128 + 64 + 32 + 16;
			} else if (n < 4096) {
				a1 = 255;
				a2 = 128 + 64 + 32 + 16 + 8;
			} else if (n < 8192) {
				a1 = 255;
				a2 = 128 + 64 + 32 + 16 + 8 + 4;
			} else if (n < 32768) {
				a1 = 255;
				a2 = 128 + 64 + 32 + 16 + 8 + 4 + 2;
			} else if (n < 65536) {
				a1 = 255;
				a2 = 255;
				a3 = 128;
			} else if (n < 131072) {
				a1 = 255;
				a2 = 255;
				a3 = 128 + 64;
			} else if (n < 262144) {
				a1 = 255;
				a2 = 255;
				a3 = 128 + 64 + 32;
			} else if (n < 524288) {
				a1 = 255;
				a2 = 255;
				a3 = 128 + 64 + 32 + 16;
			} else if (n < 1048576) {
				a1 = 255;
				a2 = 255;
				a3 = 128 + 64 + 32 + 16 + 8;
			} else if (n < 2097152) {
				a1 = 255;
				a2 = 255;
				a3 = 128 + 64 + 32 + 16 + 8 + 4;
			} else if (n < 4194304) {
				a1 = 255;
				a2 = 255;
				a3 = 128 + 64 + 32 + 16 + 8 + 4 + 2;
			} else if (n < 8388608) {
				a1 = 255;
				a2 = 255;
				a3 = 255;
			} else {
				System.out.println("These many subnets not possible.");
				return;
			}

			System.out.println("Subnet Mask : 255." + a1 + "." + a2 + "." + a3);
			return;
		} else if (ip_array[0] <= 191) {
			if (n < 2)
				a1 = 128;
			else if (n < 4)
				a1 = 128 + 64;
			else if (n < 8)
				a1 = 128 + 64 + 32;
			else if (n < 16)
				a1 = 128 + 64 + 32 + 16;
			else if (n < 32)
				a1 = 128 + 64 + 32 + 16 + 8;
			else if (n < 64)
				a1 = 128 + 64 + 32 + 16 + 8 + 4;
			else if (n < 128)
				a1 = 128 + 64 + 32 + 16 + 8 + 4 + 2;
			else if (n < 256) {
				a1 = 255;
				a2 = 128;
			} else if (n < 512) {
				a1 = 255;
				a2 = 128 + 64;
			} else if (n < 1024) {
				a1 = 255;
				a2 = 128 + 64 + 32;
			} else if (n < 2048) {
				a1 = 255;
				a2 = 128 + 64 + 32 + 16;
			} else if (n < 4096) {
				a1 = 255;
				a2 = 128 + 64 + 32 + 16 + 8;
			} else if (n < 8192) {
				a1 = 255;
				a2 = 128 + 64 + 32 + 16 + 8 + 4;
			} else if (n < 32768) {
				a1 = 255;
				a2 = 128 + 64 + 32 + 16 + 8 + 4 + 2;
			} else {
				System.out.println("These many subnets not possible.");
				return;
			}

			System.out.println("Subnet Mask : 255.255." + a1 + "." + a2);
			return;
		} else if (ip_array[0] <= 223) {
			if (n < 2)
				a1 = 128;
			else if (n < 4)
				a1 = 128 + 64;
			else if (n < 8)
				a1 = 128 + 64 + 32;
			else if (n < 16)
				a1 = 128 + 64 + 32 + 16;
			else if (n < 32)
				a1 = 128 + 64 + 32 + 16 + 8;
			else if (n < 64)
				a1 = 128 + 64 + 32 + 16 + 8 + 4;
			else if (n < 128)
				a1 = 128 + 64 + 32 + 16 + 8 + 4 + 2;
			else {
				System.out.println("These many subnets not possible.");
				return;
			}

			System.out.println("Subnet Mask : 255.255.255." + a1);
			return;
		} else if (ip_array[0] < 239)
			System.out.println("Reserved Range of IP : No subnets possible.");
		else if (ip_array[0] < 254)
			System.out.println("Reserved Range of IP : No subnets possible.");
		else
			System.out.println("Invalid IP : No Subnets possible");
	}

	public void printIPs() {
		System.out.println("IPs : ");
		int j = 0;

		if (ip_array[0] >= 192 && ip_array[0] <= 223)
			for (int i = 0; i < n; i++) {
				j = j + (256 / n) - 1;
				System.out.print("\t");
				System.out.println(ip_array[0] + "." + ip_array[1] + "."
						+ ip_array[2] + "." + j);
			}
	}

	public static void main(String[] args) {
		boolean flag_exit = false;
		Scanner in = new Scanner(System.in);
		System.out.print("Enter the IP Address : ");
		String ip_address = in.next();
		System.out.print("Enter the Number of Subnet : ");
		int n = in.nextInt();

		Subnet subnet = new Subnet(ip_address, n);

		do {
			System.out
					.print("\nMenu: \n1. Size of Subnet\n2. Class of IP\n3. Subnet Mask"
							+ "\n4. Print IPs\n5. Print All\n6. Exit\n=> ");
			int ch = in.nextInt();
			System.out.println();
			switch (ch) {
			case 1:
				subnet.printSize();
				break;
			case 2:
				subnet.printClass();
				break;
			case 3:
				subnet.printSubnetMask();
				break;
			case 4:
				subnet.printIPs();
				break;
			case 5:
				subnet.printSize();
				subnet.printClass();
				subnet.printSubnetMask();
				subnet.printIPs();
				break;
			default:
				flag_exit = true;
				break;

			}
		} while (!flag_exit);
	}
}
/*
Enter the IP Address : 200.50.100.5
Enter the Number of Subnet : 14

Menu: 
1. Size of Subnet
2. Class of IP
3.Subnet Mask
4.Print IPs
5.Print All
6. Exit
 => 
1

Size of Subnet : 18

Menu: 
1. Size of Subnet
2. Class of IP
3.Subnet Mask
4.Print IPs
5.Print All
6. Exit
 => 
2

IP Class : C

Menu: 
1. Size of Subnet
2. Class of IP
3.Subnet Mask
4.Print IPs
5.Print All
6. Exit
 => 
3

Subnet Mask : 255.255.255.240

Menu: 
1. Size of Subnet
2. Class of IP
3.Subnet Mask
4.Print IPs
5.Print All
6. Exit
 => 
4

IPs : 
	200.50.100.17
	200.50.100.34
	200.50.100.51
	200.50.100.68
	200.50.100.85
	200.50.100.102
	200.50.100.119
	200.50.100.136
	200.50.100.153
	200.50.100.170
	200.50.100.187
	200.50.100.204
	200.50.100.221
	200.50.100.238

Menu: 
1. Size of Subnet
2. Class of IP
3.Subnet Mask
4.Print IPs
5.Print All
6. Exit
 => 
5

Size of Subnet : 18
IP Class : C
Subnet Mask : 255.255.255.240
IPs : 
	200.50.100.17
	200.50.100.34
	200.50.100.51
	200.50.100.68
	200.50.100.85
	200.50.100.102
	200.50.100.119
	200.50.100.136
	200.50.100.153
	200.50.100.170
	200.50.100.187
	200.50.100.204
	200.50.100.221
	200.50.100.238

Menu: 
1. Size of Subnet
2. Class of IP
3.Subnet Mask
4.Print IPs
5.Print All
6. Exit
 => 
6
 */
