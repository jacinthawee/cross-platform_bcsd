
ulong X509_issuer_and_serial_hash(X509 *a)

{
  undefined *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  ASN1_INTEGER *pAVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  ulong uVar10;
  undefined auStack_44 [24];
  uint local_2c [4];
  int *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int **)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_44);
  puVar2 = (uint *)X509_NAME_oneline(a->cert_info->issuer,(char *)0x0,0);
  puVar3 = (uint *)(*(code *)PTR_EVP_md5_006a81c8)();
  iVar4 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_44,puVar3,0);
  if (iVar4 != 0) {
    uVar5 = (*(code *)PTR_strlen_006aab30)(puVar2);
    puVar3 = puVar2;
    iVar4 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_44,puVar2,uVar5);
    if (iVar4 != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(puVar2);
      pAVar6 = a->cert_info->serialNumber;
      puVar3 = (uint *)pAVar6->data;
      iVar4 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_44,puVar3,pAVar6->length);
      if (iVar4 != 0) {
        puVar3 = local_2c;
        iVar4 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_44,puVar3,0);
        if (iVar4 != 0) {
          uVar10 = (((local_2c[0] >> 0x10) << 0x18 | (local_2c[0] >> 0x18) << 0x10) >> 0x10) +
                   ((local_2c[0] & 0xff) << 8 | local_2c[0] >> 8 & 0xff) * 0x10000;
          goto LAB_00578c78;
        }
      }
    }
  }
  uVar10 = 0;
LAB_00578c78:
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_44);
  if (local_1c == *(int **)puVar1) {
    return uVar10;
  }
  piVar8 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar4 = *(int *)(*piVar8 + 0xc);
  iVar9 = *(int *)(*puVar3 + 0xc);
  if (((*(int *)(iVar4 + 0xc) == 0) || (*(int *)(iVar4 + 4) != 0)) &&
     (iVar7 = (*(code *)PTR_i2d_X509_NAME_006a87d8)(iVar4,0), iVar7 < 0)) {
    uVar10 = 0xfffffffe;
  }
  else if (((*(int *)(iVar9 + 0xc) == 0) || (*(int *)(iVar9 + 4) != 0)) &&
          (iVar7 = (*(code *)PTR_i2d_X509_NAME_006a87d8)(iVar9,0), iVar7 < 0)) {
    uVar10 = 0xfffffffe;
  }
  else {
    uVar10 = *(int *)(iVar4 + 0x10) - *(int *)(iVar9 + 0x10);
    if (uVar10 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00578dd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar10 = (*(code *)PTR_memcmp_006aabd8)
                         (*(undefined4 *)(iVar4 + 0xc),*(undefined4 *)(iVar9 + 0xc));
      return uVar10;
    }
  }
  return uVar10;
}

