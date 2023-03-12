
uint n_ssl3_mac(int param_1,undefined *param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint in_t3;
  int iVar13;
  char *pcVar14;
  uint *puVar15;
  undefined4 uVar16;
  int iVar17;
  undefined local_99;
  uint local_98;
  uint local_94;
  undefined auStack_90 [24];
  undefined auStack_78 [8];
  undefined auStack_70 [68];
  byte *local_2c;
  
  puVar5 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(byte **)PTR___stack_chk_guard_006a9ae8;
  iVar13 = *(int *)(param_1 + 0x58);
  puVar15 = (uint *)(iVar13 + 0x10c);
  if (param_3 == 0) {
    uVar16 = *(undefined4 *)(param_1 + 0x84);
    iVar17 = iVar13 + 0x14;
    pcVar14 = (char *)(iVar13 + 8);
  }
  else {
    uVar16 = *(undefined4 *)(param_1 + 0x90);
    puVar15 = (uint *)(iVar13 + 0x130);
    iVar17 = iVar13 + 0x60;
    pcVar14 = (char *)(iVar13 + 0x54);
  }
  uVar6 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(uVar16);
  uVar7 = (*(code *)PTR_EVP_MD_size_006a7e3c)(uVar6);
  if ((int)uVar7 < 0) {
LAB_00489054:
    uVar7 = 0xffffffff;
  }
  else {
    uVar8 = puVar15[1];
    uVar12 = *puVar15;
    if (uVar7 == 0) {
      trap(7);
    }
    *puVar15 = uVar12 & 0xff;
    iVar13 = (0x30 / uVar7) * uVar7;
    local_98 = uVar7;
    if (((param_3 == 0) &&
        (uVar10 = (*(code *)PTR_EVP_CIPHER_CTX_flags_006a8108)(*(undefined4 *)(param_1 + 0x80)),
        (uVar10 & 0xf0007) == 2)) &&
       (iVar9 = ssl3_cbc_record_digest_supported(uVar16), uVar10 = local_98, iVar9 != 0)) {
      iVar9 = (*(code *)PTR___memcpy_chk_006a9a48)(auStack_78,iVar17,local_98,0x4b);
      (*(code *)PTR_memcpy_006a9aec)
                (iVar9 + uVar10,"666666666666666666666666666666666666666666666666",iVar13);
      uVar2 = (uint)pcVar14 & 3;
      uVar11 = *(uint *)(pcVar14 + 4);
      iVar13 = iVar13 + uVar10;
      uVar3 = (uint)(pcVar14 + 3) & 3;
      *(uint *)(iVar9 + iVar13) =
           (*(int *)(pcVar14 + -uVar2) << uVar2 * 8 | in_t3 & 0xffffffffU >> (4 - uVar2) * 8) &
           -1 << (uVar3 + 1) * 8 | *(uint *)(pcVar14 + 3 + -uVar3) >> (3 - uVar3) * 8;
      ((uint *)(iVar9 + iVar13))[1] = uVar11;
      auStack_70[iVar13] = (char)*puVar15;
      auStack_70[iVar13 + 1] = (char)(puVar15[1] >> 8);
      auStack_70[iVar13 + 2] = (char)puVar15[1];
      iVar13 = ssl3_cbc_digest_record
                         (uVar16,param_2,&local_98,iVar9,puVar15[4],uVar10 + puVar15[1],
                          (uVar12 >> 8) + uVar8 + uVar7,iVar17,uVar10,1);
      if (iVar13 < 1) goto LAB_00489054;
    }
    else {
      (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_90);
      puVar4 = PTR_EVP_MD_CTX_copy_ex_006a8104;
      uVar7 = *puVar15;
      *param_2 = (char)(puVar15[1] >> 8);
      local_99 = (undefined)uVar7;
      param_2[1] = (char)puVar15[1];
      iVar9 = (*(code *)puVar4)(auStack_90,uVar16);
      if ((((iVar9 < 1) ||
           (iVar9 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_90,iVar17,local_98), iVar9 < 1)
           ) || ((iVar9 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                                    (auStack_90,"666666666666666666666666666666666666666666666666",
                                     iVar13), iVar9 < 1 ||
                 ((iVar9 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_90,pcVar14,8), iVar9 < 1
                  || (iVar9 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_90,&local_99,1),
                     iVar9 < 1)))))) ||
         ((iVar9 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_90,param_2,2), iVar9 < 1 ||
          (((((iVar9 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_90,puVar15[4],puVar15[1]),
              iVar9 < 1 ||
              (iVar9 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_90,param_2,0), iVar9 < 1))
             || (iVar9 = (*(code *)PTR_EVP_MD_CTX_copy_ex_006a8104)(auStack_90,uVar16), iVar9 < 1))
            || ((iVar17 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_90,iVar17,local_98),
                iVar17 < 1 ||
                (iVar13 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                                    (auStack_90,
                                     "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\666666666666666666666666666666666666666666666666"
                                     ,iVar13), iVar13 < 1)))) ||
           ((iVar13 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_90,param_2,local_98),
            iVar13 < 1 ||
            (iVar13 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_90,param_2,&local_94),
            iVar13 < 1)))))))) {
        (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_90);
        uVar7 = 0xffffffff;
        goto LAB_00488ebc;
      }
      local_98 = local_94;
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_90);
    }
    cVar1 = pcVar14[7];
    pcVar14[7] = cVar1 + '\x01';
    uVar7 = local_98;
    if ((((char)(cVar1 + '\x01') == '\0') &&
        (cVar1 = pcVar14[6], pcVar14[6] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
       ((cVar1 = pcVar14[5], pcVar14[5] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
        ((((cVar1 = pcVar14[4], pcVar14[4] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0' &&
           (cVar1 = pcVar14[3], pcVar14[3] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
          (cVar1 = pcVar14[2], pcVar14[2] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')) &&
         (cVar1 = pcVar14[1], pcVar14[1] = cVar1 + '\x01', (char)(cVar1 + '\x01') == '\0')))))) {
      *pcVar14 = *pcVar14 + '\x01';
    }
  }
LAB_00488ebc:
  if (local_2c != *(byte **)puVar5) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    uVar7 = local_2c[7] + 1 & 0xff;
    local_2c[7] = (byte)uVar7;
    if (uVar7 == 0) {
      uVar7 = local_2c[6] + 1 & 0xff;
      local_2c[6] = (byte)uVar7;
      if (uVar7 == 0) {
        uVar7 = local_2c[5] + 1 & 0xff;
        local_2c[5] = (byte)uVar7;
        if (uVar7 == 0) {
          uVar7 = local_2c[4] + 1 & 0xff;
          local_2c[4] = (byte)uVar7;
          if (uVar7 == 0) {
            uVar7 = local_2c[3] + 1 & 0xff;
            local_2c[3] = (byte)uVar7;
            if (uVar7 == 0) {
              uVar7 = local_2c[2] + 1 & 0xff;
              local_2c[2] = (byte)uVar7;
              if (uVar7 == 0) {
                uVar7 = local_2c[1] + 1 & 0xff;
                local_2c[1] = (byte)uVar7;
                if (uVar7 == 0) {
                  uVar7 = *local_2c + 1;
                  *local_2c = (byte)uVar7;
                }
              }
            }
          }
        }
      }
    }
    return uVar7;
  }
  return uVar7;
}

