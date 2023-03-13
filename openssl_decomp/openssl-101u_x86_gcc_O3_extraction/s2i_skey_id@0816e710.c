
ASN1_STRING * s2i_skey_id(undefined4 param_1,int *param_2,char *param_3)

{
  ASN1_STRING *a;
  EVP_MD *type;
  uchar *puVar1;
  int iVar2;
  size_t *psVar3;
  char *pcVar4;
  char *pcVar5;
  int in_GS_OFFSET;
  bool bVar6;
  uint local_64;
  uchar local_60 [64];
  int local_20;
  
  iVar2 = 5;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar6 = true;
  pcVar4 = param_3;
  pcVar5 = "hash";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar4 == *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar6);
  if (!bVar6) {
    a = ASN1_STRING_type_new(4);
    if (a == (ASN1_STRING *)0x0) {
      ERR_put_error(0x22,0x70,0x41,"v3_skey.c",0x57);
      a = (ASN1_STRING *)0x0;
    }
    else {
      puVar1 = string_to_hex(param_3,(long *)&local_64);
      a->data = puVar1;
      if (puVar1 == (uchar *)0x0) {
        ASN1_STRING_free(a);
        a = (ASN1_STRING *)0x0;
      }
      else {
        a->length = local_64;
      }
    }
    goto LAB_0816e7c5;
  }
  a = ASN1_STRING_type_new(4);
  if (a == (ASN1_STRING *)0x0) {
    ERR_put_error(0x22,0x73,0x41,"v3_skey.c",0x72);
    a = (ASN1_STRING *)0x0;
    goto LAB_0816e7c5;
  }
  if (param_2 == (int *)0x0) {
LAB_0816e8b0:
    iVar2 = 0x7a;
LAB_0816e825:
    ERR_put_error(0x22,0x73,0x72,"v3_skey.c",iVar2);
  }
  else {
    if (*param_2 == 1) goto LAB_0816e7c5;
    if ((int *)param_2[3] == (int *)0x0) {
      if ((int *)param_2[2] == (int *)0x0) goto LAB_0816e8b0;
      psVar3 = *(size_t **)(*(int *)(*(int *)param_2[2] + 0x18) + 4);
    }
    else {
      psVar3 = *(size_t **)(*(int *)(*(int *)param_2[3] + 0x14) + 4);
    }
    if (psVar3 == (size_t *)0x0) {
      iVar2 = 0x84;
      goto LAB_0816e825;
    }
    type = EVP_sha1();
    iVar2 = EVP_Digest((void *)psVar3[2],*psVar3,local_60,&local_64,type,(ENGINE *)0x0);
    if (iVar2 != 0) {
      iVar2 = ASN1_STRING_set(a,local_60,local_64);
      if (iVar2 != 0) goto LAB_0816e7c5;
      ERR_put_error(0x22,0x73,0x41,"v3_skey.c",0x8d);
    }
  }
  ASN1_STRING_free(a);
  a = (ASN1_STRING *)0x0;
LAB_0816e7c5:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return a;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

