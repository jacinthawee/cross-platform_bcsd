
int PEM_write_NETSCAPE_CERT_SEQUENCE(FILE *fp,NETSCAPE_CERT_SEQUENCE *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write(PTR_i2d_NETSCAPE_CERT_SEQUENCE_006a8e54,"CERTIFICATE",fp,x,
                         (EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
  return iVar1;
}
