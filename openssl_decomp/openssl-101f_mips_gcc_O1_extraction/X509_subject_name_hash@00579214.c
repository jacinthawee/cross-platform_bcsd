
ulong X509_subject_name_hash(X509 *x)

{
  undefined *puVar1;
  int iVar2;
  ulong uVar3;
  X509 *x_00;
  undefined4 *puVar4;
  int *piVar5;
  X509 *x_01;
  X509_NAME *pXVar6;
  int iVar7;
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
  
  psStack_54 = (stack_st_void *)PTR___stack_chk_guard_006aabf0;
  pXVar6 = x->cert_info->subject;
  local_30 = (AUTHORITY_KEYID *)&_gp;
  local_14 = *(int **)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_i2d_X509_NAME_006a87d8)(pXVar6,0);
  puStack_50 = pXVar6->canon_enc;
  pcStack_58 = (char *)pXVar6->canon_enclen;
  local_38 = (*(code *)local_30[-0xa03].serial)();
  local_34 = (ASN1_OCTET_STRING *)0x0;
  iVar2 = (*(code *)local_30[-0x9a8].issuer)(puStack_50,pcStack_58,local_28,0);
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
  piVar5 = local_14;
  (*(code *)local_30[-0x6ee].keyid)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar7 = *(int *)(*piVar5 + 0x14);
  pXStack_5c = *(X509 **)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_i2d_X509_NAME_006a87d8)(iVar7,0);
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_84);
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a8600)(auStack_84,8);
  x_00 = (X509 *)(*(code *)PTR_EVP_md5_006a81c8)();
  iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_84,x_00,0);
  if (iVar2 != 0) {
    puVar4 = *(undefined4 **)(iVar7 + 8);
    x_00 = (X509 *)puVar4[1];
    iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_84,x_00,*puVar4);
    if (iVar2 != 0) {
      x_00 = (X509 *)&pXStack_6c;
      iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_84,x_00,0);
      if (iVar2 != 0) {
        uVar3 = ((((uint)pXStack_6c >> 0x10) << 0x18 | ((uint)pXStack_6c >> 0x18) << 0x10) >> 0x10)
                + (((uint)pXStack_6c & 0xff) << 8 | (uint)pXStack_6c >> 8 & 0xff) * 0x10000;
        goto LAB_00579384;
      }
    }
  }
  uVar3 = 0;
LAB_00579384:
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_84);
  if (pXStack_5c == *(X509 **)puVar1) {
    return uVar3;
  }
  x_01 = pXStack_5c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  X509_check_purpose(x_01,-1,0);
  X509_check_purpose(x_00,-1,0);
                    /* WARNING: Could not recover jumptable at 0x00579480. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*(code *)PTR_memcmp_006aabd8)(&x_01->rfc3779_addr,&x_00->rfc3779_addr,0x14);
  return uVar3;
}

