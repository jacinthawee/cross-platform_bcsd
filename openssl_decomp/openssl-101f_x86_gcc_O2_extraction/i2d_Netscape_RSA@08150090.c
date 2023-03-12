
int i2d_Netscape_RSA(RSA *a,uchar **pp,cb *cb)

{
  int iVar1;
  
  iVar1 = i2d_RSA_NET(a,pp,cb,0);
  return iVar1;
}

