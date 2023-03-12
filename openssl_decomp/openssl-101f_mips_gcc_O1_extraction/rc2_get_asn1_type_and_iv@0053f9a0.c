
char * rc2_get_asn1_type_and_iv(EVP_CIPHER_CTX *param_1,int *param_2,uchar *param_3,char *param_4)

{
  undefined *puVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  EVP_CIPHER_CTX *ctx;
  int *piVar5;
  int *unaff_s2;
  EVP_CIPHER_CTX *unaff_s3;
  uchar *puVar6;
  int iStack_78;
  int iStack_74;
  char *pcStack_6c;
  undefined *puStack_68;
  int *piStack_64;
  EVP_CIPHER_CTX *pEStack_60;
  code *pcStack_5c;
  int local_38;
  uchar auStack_34 [16];
  EVP_CIPHER_CTX *local_24;
  
  puStack_68 = PTR___stack_chk_guard_006aabf0;
  local_38 = 0;
  local_24 = *(EVP_CIPHER_CTX **)PTR___stack_chk_guard_006aabf0;
  if (param_2 == (int *)0x0) {
    pcStack_6c = (char *)0x0;
    goto LAB_0053faa8;
  }
  pcStack_6c = (char *)EVP_CIPHER_CTX_iv_length(param_1);
  if ((char *)0x10 < pcStack_6c) {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("e_rc2.c",0xb3,"l <= sizeof(iv)");
  }
  piVar5 = &local_38;
  param_3 = auStack_34;
  param_4 = pcStack_6c;
  pcVar2 = (char *)(*(code *)PTR_ASN1_TYPE_get_int_octetstring_006a9ba4)(param_2,piVar5,auStack_34);
  unaff_s2 = param_2;
  unaff_s3 = param_1;
  if (pcStack_6c == pcVar2) {
    if (local_38 == 0x3a) {
      unaff_s2 = (int *)&SUB_00000010;
      puVar6 = &DAT_00000080;
    }
    else if (local_38 == 0x78) {
      unaff_s2 = (int *)&DAT_00000008;
      puVar6 = &DAT_00000040;
    }
    else {
      unaff_s2 = (int *)&DAT_00000005;
      if (local_38 != 0xa0) {
        param_3 = &DAT_0000006c;
        param_4 = "e_rc2.c";
        piVar5 = (int *)&DAT_0000006d;
        ERR_put_error(6,0x6d,0x6c,"e_rc2.c",0xa3);
        goto LAB_0053fb10;
      }
      puVar6 = (uchar *)0x28;
    }
    if (0 < (int)pcStack_6c) {
      param_4 = (char *)0x0;
      param_3 = (uchar *)0x0;
      piVar5 = (int *)0x0;
      iVar3 = EVP_CipherInit_ex(param_1,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,auStack_34,-1);
      if (iVar3 == 0) goto LAB_0053fb10;
    }
    param_4 = (char *)0x0;
    EVP_CIPHER_CTX_ctrl(param_1,3,(int)puVar6,(void *)0x0);
    param_2 = unaff_s2;
    EVP_CIPHER_CTX_set_key_length(param_1,(int)unaff_s2);
    param_3 = puVar6;
  }
  else {
LAB_0053fb10:
    pcStack_6c = (char *)0xffffffff;
    param_2 = piVar5;
  }
LAB_0053faa8:
  if (local_24 == *(EVP_CIPHER_CTX **)puStack_68) {
    return pcStack_6c;
  }
  pcStack_5c = rc2_set_asn1_type_and_iv;
  ctx = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_74 = *(int *)PTR___stack_chk_guard_006aabf0;
  piStack_64 = unaff_s2;
  pEStack_60 = unaff_s3;
  if (param_2 == (int *)0x0) {
    pcVar2 = (char *)0x0;
  }
  else {
    EVP_CIPHER_CTX_ctrl(ctx,2,0,&iStack_78);
    if (iStack_78 == 0x80) {
      piVar5 = (int *)&DAT_0000003a;
    }
    else if (iStack_78 == 0x40) {
      piVar5 = (int *)&DAT_00000078;
    }
    else {
      piVar5 = (int *)&DAT_000000a0;
      if (iStack_78 != 0x28) {
        piVar5 = (int *)0x0;
      }
    }
    param_4 = (char *)EVP_CIPHER_CTX_iv_length(ctx);
    param_3 = ctx->oiv;
    pcVar2 = (char *)(*(code *)PTR_ASN1_TYPE_set_int_octetstring_006a9bac)(param_2,piVar5,param_3);
    param_2 = piVar5;
  }
  if (iStack_74 != *(int *)puVar1) {
    iVar3 = iStack_74;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if ((char *)0x3fffffff < param_4) {
      piVar5 = param_2;
      puVar6 = param_3;
      pcVar2 = param_4;
      do {
        pcVar2 = pcVar2 + -0x40000000;
        (*(code *)PTR_RC2_cbc_encrypt_006a8b44)
                  (puVar6,piVar5,0x40000000,*(int *)(iVar3 + 0x60) + 4,iVar3 + 0x20,
                   *(undefined4 *)(iVar3 + 8));
        puVar6 = puVar6 + 0x40000000;
        piVar5 = piVar5 + 0x10000000;
      } while ((char *)0x3fffffff < pcVar2);
      pcVar2 = param_4 + -0x40000000;
      param_4 = (char *)((uint)param_4 & 0x3fffffff);
      iVar4 = ((uint)pcVar2 >> 0x1e) + 1;
      param_3 = param_3 + iVar4 * 0x40000000;
      param_2 = param_2 + iVar4 * 0x10000000;
    }
    if (param_4 != (char *)0x0) {
      (*(code *)PTR_RC2_cbc_encrypt_006a8b44)
                (param_3,param_2,param_4,*(int *)(iVar3 + 0x60) + 4,iVar3 + 0x20,
                 *(undefined4 *)(iVar3 + 8));
    }
    return (char *)0x1;
  }
  return pcVar2;
}

