
ulong X509_issuer_name_hash(X509 *a)

{
  undefined *puVar1;
  int iVar2;
  ulong uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  X509_NAME *pXVar7;
  int iVar8;
  undefined auStack_84 [24];
  uint auStack_6c [4];
  int *piStack_5c;
  int iStack_58;
  undefined *puStack_54;
  uchar *puStack_50;
  code *pcStack_4c;
  undefined4 local_38;
  undefined4 local_34;
  undefined *local_30;
  uint local_28 [5];
  int *local_14;
  
  puStack_54 = PTR___stack_chk_guard_006aabf0;
  pXVar7 = a->cert_info->issuer;
  local_30 = &_gp;
  local_14 = *(int **)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_i2d_X509_NAME_006a87d8)(pXVar7,0);
  puStack_50 = pXVar7->canon_enc;
  iStack_58 = pXVar7->canon_enclen;
  local_38 = (**(code **)(local_30 + -0x781c))();
  local_34 = 0;
  iVar2 = (**(code **)(local_30 + -0x73dc))(puStack_50,iStack_58,local_28,0);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (((local_28[0] >> 0x10) << 0x18 | (local_28[0] >> 0x18) << 0x10) >> 0x10) +
            ((local_28[0] & 0xff) << 8 | local_28[0] >> 8 & 0xff) * 0x10000;
  }
  if (local_14 == *(int **)puStack_54) {
    return uVar3;
  }
  pcStack_4c = X509_issuer_name_hash_old;
  piVar6 = local_14;
  (**(code **)(local_30 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar8 = *(int *)(*piVar6 + 0xc);
  piStack_5c = *(int **)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_i2d_X509_NAME_006a87d8)(iVar8,0);
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_84);
  (*(code *)PTR_EVP_MD_CTX_set_flags_006a8600)(auStack_84,8);
  uVar4 = (*(code *)PTR_EVP_md5_006a81c8)();
  iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_84,uVar4,0);
  if (iVar2 != 0) {
    puVar5 = *(undefined4 **)(iVar8 + 8);
    iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_84,puVar5[1],*puVar5);
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_84,auStack_6c,0);
      if (iVar2 != 0) {
        uVar3 = (((auStack_6c[0] >> 0x10) << 0x18 | (auStack_6c[0] >> 0x18) << 0x10) >> 0x10) +
                ((auStack_6c[0] & 0xff) << 8 | auStack_6c[0] >> 8 & 0xff) * 0x10000;
        goto LAB_0057916c;
      }
    }
  }
  uVar3 = 0;
LAB_0057916c:
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_84);
  if (piStack_5c == *(int **)puVar1) {
    return uVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return *(ulong *)(*piStack_5c + 0x14);
}

