
int bitstr_cb(char *param_1,int param_2,ASN1_BIT_STRING *param_3)

{
  ulong n;
  int iVar1;
  int in_GS_OFFSET;
  char *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1 != (char *)0x0) {
    n = strtoul(param_1,&local_14,10);
    if (((local_14 == (char *)0x0) || (*local_14 == '\0')) || (local_14 == param_1 + param_2)) {
      if (-1 < (int)n) {
        iVar1 = ASN1_BIT_STRING_set_bit(param_3,n,1);
        if (iVar1 == 0) {
          ERR_put_error(0xd,0xb4,0x41,"asn1_gen.c",0x351);
        }
        else {
          iVar1 = 1;
        }
        goto LAB_08150c67;
      }
      ERR_put_error(0xd,0xb4,0xbb,"asn1_gen.c",0x34c);
    }
  }
  iVar1 = 0;
LAB_08150c67:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

