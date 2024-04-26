import java.util.Scanner;


public class subnetting {


	public static void main(String[] args) {
		String cl=null;
		int a=0,b=0,c=0,d=0,n=0,sn = 0 ,di=0,cla=0;
		String Subnet=null;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Ip Address");
		String ip;
		ip=sc.nextLine();

		a=Integer.parseInt(ip.split("\\.")[0]);
		b=Integer.parseInt(ip.split("\\.")[1]);
		c=Integer.parseInt(ip.split("\\.")[2]);
		d=Integer.parseInt(ip.split("\\.")[3]);

		if(a<128)
		{
			cl="A";
			cla=1;
		}
		else if(a<192)
		{
			cl="B";
			cla=2;
		}
		else if(a<223)
		{
			cl="c";
			cla=3;
		}
		else if(a<239)
			cl="D";

		System.out.println("Class of IP address is "+cl);

		switch(cla)
		{
		case 1:Subnet="255.0.0.0";
		break;
		case 2:Subnet="255.255.0.0";
		break;
		case 3:Subnet="255.255.255.0";
		break;
		default:Subnet="";
		break;
		}

		System.out.println("Default Subnet Mask:"+Subnet);

		System.out.println("Enter number of Subnets to be created:");
		n=sc.nextInt();

		if(n<3)
			sn=128;
		else if(n<5)
			sn=192;
		else if(n<9)
			sn=224;
		else if(n<17)
			sn=240;
		else if(n<33)
			sn=248;
		else if(n<65)
			sn=252;
		else if(n<129)
			sn=254;
		else if(n<256)
			sn=255;

		di=256-sn-1;
		if(cl.equals("A"))
		{
			System.out.println("new Subnet mask is 255."+sn+".0.0");
			int dj=b;
			System.out.println("Subnet Ranges:");
			for(int i=0;i<n;i++)
			{
				System.out.println((i+1)+":"+""+a+"."+(dj)+".0.0 to "+a+"."+(dj+di)+".0.0");
				dj+=di;
			}
		}
		else if(cl.equals("B"))
		{
			System.out.println("new Subnet mask is 255.255."+sn+".0");
			int dj=c;
			System.out.println("Subnet Ranges:");
			for(int i=0;i<n;i++)
			{
				System.out.println((i+1)+":"+""+a+"."+b+"."+(dj)+".0 to "+a+"."+b+"."+(dj+di)+".0");
				dj+=di;
			}
		}
		else if(cl.equals("c"))
		{
			System.out.println("new Subnet mask is 255.255.255."+sn);
			int dj=d;
			System.out.println("Subnet Ranges:");
			for(int i=0;i<n;i++)
			{
				System.out.println((i+1)+":"+""+a+"."+b+"."+c+"."+dj+" to "+a+"."+b+"."+c+"."+(dj+di));
				dj+=di+1;
				
			}
		}
	}
}
