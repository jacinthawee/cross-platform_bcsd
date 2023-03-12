
int PKCS8_add_keyusage(PKCS8_PRIV_KEY_INFO *p8,int usage)

{
  stack_st_X509_ATTRIBUTE *psVar1;
  int in_GS_OFFSET;
  uchar local_11;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_11 = (uchar)usage;
  psVar1 = X509at_add1_attr_by_NID(&p8->attributes,0x53,3,&local_11,1);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (uint)(psVar1 != (stack_st_X509_ATTRIBUTE *)0x0);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

