
void s2i_skey_id(undefined4 param_1,int *param_2,char *param_3)

{
  int iVar1;
  ASN1_STRING *a;
  EVP_MD *type;
  ASN1_STRING *pAVar2;
  size_t *psVar3;
  void *data;
  size_t count;
  uint local_60;
  uchar auStack_5c [64];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  iVar1 = strcmp(param_3,"hash");
  if (iVar1 != 0) {
    a = ASN1_STRING_type_new(4);
    if (a == (ASN1_STRING *)0x0) {
      ERR_put_error(0x22,0x70,0x41,"v3_skey.c",0x57);
    }
    else {
      pAVar2 = (ASN1_STRING *)string_to_hex(param_3,(long *)&local_60);
      a->data = (uchar *)pAVar2;
      if (pAVar2 == (ASN1_STRING *)0x0) {
        ASN1_STRING_free(a);
        a = pAVar2;
      }
      else {
        a->length = local_60;
      }
    }
    goto LAB_000d2408;
  }
  a = ASN1_STRING_type_new(4);
  if (a == (ASN1_STRING *)0x0) {
    ERR_put_error(0x22,0x73,0x41,"v3_skey.c",0x72);
    goto LAB_000d2408;
  }
  if (param_2 == (int *)0x0) {
LAB_000d2494:
    iVar1 = 0x7a;
LAB_000d243c:
    ERR_put_error(0x22,0x73,0x72,"v3_skey.c",iVar1);
  }
  else {
    if (*param_2 == 1) goto LAB_000d2408;
    if ((int *)param_2[3] == (int *)0x0) {
      if ((int *)param_2[2] == (int *)0x0) goto LAB_000d2494;
      psVar3 = *(size_t **)(*(int *)(*(int *)param_2[2] + 0x18) + 4);
    }
    else {
      psVar3 = *(size_t **)(*(int *)(*(int *)param_2[3] + 0x14) + 4);
    }
    if (psVar3 == (size_t *)0x0) {
      iVar1 = 0x84;
      goto LAB_000d243c;
    }
    data = (void *)psVar3[2];
    count = *psVar3;
    type = EVP_sha1();
    iVar1 = EVP_Digest(data,count,auStack_5c,&local_60,type,(ENGINE *)0x0);
    if (iVar1 != 0) {
      iVar1 = ASN1_STRING_set(a,auStack_5c,local_60);
      if (iVar1 != 0) goto LAB_000d2408;
      ERR_put_error(0x22,0x73,0x41,"v3_skey.c",0x8d);
    }
  }
  ASN1_STRING_free(a);
  a = (ASN1_STRING *)0x0;
LAB_000d2408:
  if (local_1c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(a);
  }
  return;
}

