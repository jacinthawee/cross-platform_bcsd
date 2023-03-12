
void ocsp_match_issuerid(X509 *param_1,undefined4 *param_2,_STACK *param_3)

{
  int iVar1;
  char *name;
  EVP_MD *md;
  size_t __n;
  uint uVar2;
  undefined4 *puVar3;
  X509_NAME *data;
  uchar auStack_5c [64];
  int local_1c;
  
  local_1c = __TMC_END__;
  if (param_2 == (undefined4 *)0x0) {
    for (; iVar1 = sk_num(param_3), (int)param_2 < iVar1; param_2 = (undefined4 *)((int)param_2 + 1)
        ) {
      puVar3 = (undefined4 *)sk_value(param_3,(int)param_2);
      uVar2 = ocsp_match_issuerid(param_1,*puVar3,0);
      if ((int)uVar2 < 1) goto LAB_000e311a;
    }
    uVar2 = 1;
    goto LAB_000e311a;
  }
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)*param_2);
  name = OBJ_nid2sn(iVar1);
  md = EVP_get_digestbyname(name);
  if (md == (EVP_MD *)0x0) {
    ERR_put_error(0x27,0x6d,0x77,"ocsp_vfy.c",0x136);
    uVar2 = 0xffffffff;
    goto LAB_000e311a;
  }
  __n = EVP_MD_size(md);
  if ((int)__n < 0) {
LAB_000e314e:
    uVar2 = 0xffffffff;
  }
  else {
    if ((__n == *(size_t *)param_2[1]) && (__n == *(size_t *)param_2[2])) {
      data = X509_get_subject_name(param_1);
      iVar1 = X509_NAME_digest(data,md,auStack_5c,(uint *)0x0);
      if (iVar1 == 0) goto LAB_000e314e;
      iVar1 = memcmp(auStack_5c,*(void **)(param_2[1] + 8),__n);
      if (iVar1 == 0) {
        X509_pubkey_digest(param_1,md,auStack_5c,(uint *)0x0);
        iVar1 = memcmp(auStack_5c,*(void **)(param_2[2] + 8),__n);
        uVar2 = count_leading_zeroes(iVar1);
        uVar2 = uVar2 >> 5;
        goto LAB_000e311a;
      }
    }
    uVar2 = 0;
  }
LAB_000e311a:
  if (local_1c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar2);
}

