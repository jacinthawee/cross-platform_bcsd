
ulong X509_subject_name_hash(X509 *x)

{
  undefined *puVar1;
  int iVar2;
  ulong uVar3;
  X509 *x_00;
  undefined4 *puVar4;
  X509_CINF *pXVar5;
  int *piVar6;
  X509 *x_01;
  X509_CINF *pXVar7;
  X509_NAME *pXVar8;
  int iVar9;
  undefined auStack_84 [24];
  X509_CINF *pXStack_6c;
  X509 *pXStack_5c;
  char *pcStack_58;
  stack_st_void *psStack_54;
  uchar *puStack_50;
  code *pcStack_4c;
  ulong local_38;
  ASN1_OCTET_STRING *local_34;
  AUTHORITY_KEYID *local_30;
  stack_st_DIST_POINT *local_28 [5];
  int *local_14;
  
  psStack_54 = (stack_st_void *)PTR___stack_chk_guard_006a9ae8;
  pXVar8 = x->cert_info->subject;
  local_30 = (AUTHORITY_KEYID *)&_gp;
  local_14 = *(int **)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_i2d_X509_NAME_006a76ec)(pXVar8,0);
  puStack_50 = pXVar8->canon_enc;
  pcStack_58 = (char *)pXVar8->canon_enclen;
  local_38 = (*(code *)local_30[-0xa02].serial)();
  local_34 = (ASN1_OCTET_STRING *)0x0;
  iVar2 = (*(code *)local_30[-0x9a7].serial)(puStack_50,pcStack_58,local_28,0);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = ((((uint)local_28[0] >> 0x10) << 0x18 | ((uint)local_28[0] >> 0x18) << 0x10) >> 0x10) +
            (((uint)local_28[0] & 0xff) << 8 | (uint)local_28[0] >> 8 & 0xff) * 0x10000;
  }
  if (local_14 == *(int **)psStack_54) {
    return uVar3;
  }
  pcStack_4c = X509_subject_name_hash_old;
  piVar6 = local_14;
  (*(code *)local_30[-0x6ef].issuer)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar9 = *(int *)(*piVar6 + 0x14);
  pXStack_5c = *(X509 **)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_i2d_X509_NAME_006a76ec)(iVar9,0);
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_84);
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a7504)(auStack_84,8);
  x_00 = (X509 *)(*(code *)PTR_EVP_md5_006a70c8)();
  iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_84,x_00,0);
  if (iVar2 != 0) {
    puVar4 = *(undefined4 **)(iVar9 + 8);
    x_00 = (X509 *)puVar4[1];
    iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_84,x_00,*puVar4);
    if (iVar2 != 0) {
      x_00 = (X509 *)&pXStack_6c;
      iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_84,x_00,0);
      if (iVar2 != 0) {
        uVar3 = ((((uint)pXStack_6c >> 0x10) << 0x18 | ((uint)pXStack_6c >> 0x18) << 0x10) >> 0x10)
                + (((uint)pXStack_6c & 0xff) << 8 | (uint)pXStack_6c >> 8 & 0xff) * 0x10000;
        goto LAB_00575b64;
      }
    }
  }
  uVar3 = 0;
LAB_00575b64:
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_84);
  if (pXStack_5c == *(X509 **)puVar1) {
    return uVar3;
  }
  x_01 = pXStack_5c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  X509_check_purpose(x_01,-1,0);
  X509_check_purpose(x_00,-1,0);
  uVar3 = (*(code *)PTR_memcmp_006a9ad0)(&x_01->rfc3779_addr,&x_00->rfc3779_addr,0x14);
  if (uVar3 == 0) {
    pXVar5 = x_01->cert_info;
    uVar3 = (pXVar5->enc).modified;
    if (uVar3 == 0) {
      pXVar7 = x_00->cert_info;
      if (((pXVar7->enc).modified == 0) &&
         (uVar3 = (pXVar5->enc).len - (pXVar7->enc).len, uVar3 == 0)) {
                    /* WARNING: Could not recover jumptable at 0x00575ca4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar3 = (*(code *)PTR_memcmp_006a9ad0)((pXVar5->enc).enc,(pXVar7->enc).enc);
        return uVar3;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}

