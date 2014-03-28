#include <stdio.h>
#include <netinet/tcp.h> 
#include <socket.h>
struct ipv6_header
{
    unsigned int
        version : 4,
        traffic_class : 8,
        flow_label : 20;
    uint16_t length;
    uint8_t  next_header;
    uint8_t  hop_limit;
    struct in6_addr src;
    struct in6_addr dst;
};
 struct ipheader {
 unsigned char      iph_ihl:5, iph_ver:4;
 unsigned char      iph_tos;
 unsigned short int iph_len;
 unsigned short int iph_ident;
 unsigned char      iph_flag;
 unsigned short int iph_offset;
 unsigned char      iph_ttl;
 unsigned char      iph_protocol;
 unsigned short int iph_chksum;
 unsigned int       iph_sourceip;
 unsigned int       iph_destip;
};

struct tcpheader {

struct ipv4packet {
	struct* ipheader;
	char* payload;
}

 unsigned short csum(unsigned short *buf, int nwords)
{       //
        unsigned long sum;
        for(sum=0; nwords>0; nwords--)
                sum += *buf++;
        sum = (sum >> 16) + (sum &0xffff);
        sum += (sum >> 16);
        return (unsigned short)(~sum);

}
char* craftSYNPacket(int srcPort,int dstPort, char* srcAdr,char* dstAdr){
	char* buffer;
	int packetLength = sizeof(struct ipheader)+sizeof(struct tcphdr);
	buffer = malloc(sizeof(struct ipheader)+sizeof(struct tcphdr));
	struct ipheader * header = (struct ipheader*) buffer;
	struct tcphdr * tcpheader = (struct tcphdr*) buffer+sizeof(struct ipheader);
	memset(buffer,0,packetLenght);


	struct sockaddr_in sin, din;
	 sin.sin_family = AF_INET;
	din.sin_family = AF_INET;

// Port numbers
	sin.sin_port = htons(srcPort);
	din.sin_port = htons(dstPort);

// IP addresses
	sin.sin_addr.s_addr = inet_addr(srcAdr);
	din.sin_addr.s_addr = inet_addr(dstAdr);
	header->iph_ihl = 5;
	ip->iph_ver = 4;
	ip->iph_tos = 16;
	ip->iph_len = packetLength;
	ip->iph_ident = htons(54321);
	ip->iph_ttl = 64;
	ip->iph_protocol =  IPPROTO_TCP;
	ip->iph_sourceip = inet_addr(srcAdr);
	ip->iph_destip = inet_addr(dstArg);

	tcpheader->th_sport = htons(srcPort);
	tcpheader->th_dport = htons(dstPort);
	tcpheader->th_seq = htonl(0);
	tcpheader->th_ack = htonl(0);
	tcpheader->th_x2 = 0;
	tcpheader->th_off = TCP_HRDLEN / 4;
	tcpheader->th_flags = 0;
	tcpheader->th_flags = 1 << 1 ; //syn
	 // Window size (16 bits)
  	tcpheader->th_win = htons (65535);

  // Urgent pointer (16 bits): 0 (only valid if URG flag is set)
  	tcpheader->th_urp = htons (0);

  // TCP checksum (16 bits)
  	tcpheader->th_sum = csum (buffer, packetLength);
	

	return buffer


}

void sendPacket(){
	int sd;
	sd = socket(PF_INET,SOCK_RAW,IPPROTO_TCP);
	if (sd<0){
		perror("socket() error");
		exit(-1);
	}
	
	if(setsockopt(sd, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0)
		{
		perror("setsockopt() error");
		exit(-1);
	}
	
	 if(sendto(sd, buffer, header->iph_len, 0, (struct sockaddr *)&sin, sizeof(sin)) < 0)// Verify
	{
		perror("sendto() error");
		exit(-1);
	}
	close(sd);
}

int main(){
	sendPacket("192.168.1.17",10,100);
	return 0;
}
