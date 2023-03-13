
SXNET * sxnet_v2i(undefined4 param_1,undefined4 param_2,_STACK *param_3)

{
  char *user;
  int iVar1;
  void *pvVar2;
  ASN1_INTEGER *izone;
  SXNET *pSVar3;
  int iVar4;
  int in_GS_OFFSET;
  SXNET *local_24;
  int local_20;
  
  iVar4 = 0;
  local_24 = (SXNET *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  do {
    iVar1 = sk_num(param_3);
    pSVar3 = local_24;
    if (iVar1 <= iVar4) {
LAB_0816f4c4:
      if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return pSVar3;
    }
    pvVar2 = sk_value(param_3,iVar4);
    user = *(char **)((int)pvVar2 + 8);
    izone = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,*(char **)((int)pvVar2 + 4));
    if (izone == (ASN1_INTEGER *)0x0) {
      ERR_put_error(0x22,0x7d,0x83,"v3_sxnet.c",0x9d);
      pSVar3 = (SXNET *)0x0;
      goto LAB_0816f4c4;
    }
    iVar1 = SXNET_add_id_INTEGER(&local_24,izone,user,-1);
    if (iVar1 == 0) {
      pSVar3 = (SXNET *)0x0;
      goto LAB_0816f4c4;
    }
    iVar4 = iVar4 + 1;
  } while( true );
}

