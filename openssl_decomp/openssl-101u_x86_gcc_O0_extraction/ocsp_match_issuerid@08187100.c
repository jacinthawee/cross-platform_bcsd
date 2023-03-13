
uint __regparm3 ocsp_match_issuerid(X509 *param_1,undefined4 *param_2,_STACK *param_3)

{
  int iVar1;
  char *name;
  EVP_MD *md;
  size_t __n;
  uint uVar2;
  X509_NAME *data;
  int in_GS_OFFSET;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_2 == (undefined4 *)0x0) {
    for (; iVar1 = sk_num(param_3), (int)param_2 < iVar1; param_2 = (undefined4 *)((int)param_2 + 1)
        ) {
      sk_value(param_3,(int)param_2);
      uVar2 = ocsp_match_issuerid();
      if ((int)uVar2 < 1) goto LAB_08187163;
    }
    uVar2 = 1;
    goto LAB_08187163;
  }
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)*param_2);
  name = OBJ_nid2sn(iVar1);
  md = EVP_get_digestbyname(name);
  if (md == (EVP_MD *)0x0) {
    ERR_put_error(0x27,0x6d,0x77,"ocsp_vfy.c",0x13f);
    uVar2 = 0xffffffff;
    goto LAB_08187163;
  }
  __n = EVP_MD_size(md);
  if ((int)__n < 0) {
LAB_08187240:
    uVar2 = 0xffffffff;
  }
  else {
    if ((__n == *(size_t *)param_2[1]) && (__n == *(size_t *)param_2[2])) {
      data = X509_get_subject_name(param_1);
      iVar1 = X509_NAME_digest(data,md,local_60,(uint *)0x0);
      if (iVar1 == 0) goto LAB_08187240;
      iVar1 = memcmp(local_60,*(void **)(param_2[1] + 8),__n);
      if (iVar1 == 0) {
        X509_pubkey_digest(param_1,md,local_60,(uint *)0x0);
        iVar1 = memcmp(local_60,*(void **)(param_2[2] + 8),__n);
        uVar2 = (uint)(iVar1 == 0);
        goto LAB_08187163;
      }
    }
    uVar2 = 0;
  }
LAB_08187163:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

