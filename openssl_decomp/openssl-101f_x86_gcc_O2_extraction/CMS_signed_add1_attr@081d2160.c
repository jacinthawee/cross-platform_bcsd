
int CMS_signed_add1_attr(CMS_SignerInfo *si,X509_ATTRIBUTE *attr)

{
  stack_st_X509_ATTRIBUTE *psVar1;
  
  psVar1 = X509at_add1_attr((stack_st_X509_ATTRIBUTE **)(si + 0xc),attr);
  return (uint)(psVar1 != (stack_st_X509_ATTRIBUTE *)0x0);
}
