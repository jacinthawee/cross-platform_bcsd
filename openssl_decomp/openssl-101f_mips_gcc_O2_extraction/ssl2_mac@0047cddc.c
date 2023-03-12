
uint ssl2_mac(int param_1,uint param_2,int param_3,int param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  code *pcVar14;
  undefined *puStack_88;
  undefined auStack_40 [24];
  undefined local_28;
  undefined local_27;
  undefined local_26;
  undefined local_25;
  uint local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar4 = *(int *)(param_1 + 0x54);
  local_24 = *(uint *)PTR___stack_chk_guard_006aabf0;
  if (param_3 == 0) {
    uVar2 = *(undefined4 *)(iVar4 + 0xd0);
    uVar13 = *(undefined4 *)(iVar4 + 0x5c);
    uVar12 = *(undefined4 *)(iVar4 + 0x44);
    uVar11 = *(undefined4 *)(iVar4 + 0x50);
  }
  else {
    uVar2 = *(undefined4 *)(iVar4 + 0xd4);
    uVar13 = *(undefined4 *)(iVar4 + 0x60);
    uVar12 = *(undefined4 *)(iVar4 + 0x4c);
    uVar11 = *(undefined4 *)(iVar4 + 0x54);
  }
  local_25 = (undefined)uVar2;
  puVar6 = auStack_40;
  local_27 = (undefined)((uint)uVar2 >> 0x10);
  local_28 = (undefined)((uint)uVar2 >> 0x18);
  local_26 = (undefined)((uint)uVar2 >> 8);
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(puVar6);
  (*(code *)PTR_EVP_MD_CTX_copy_006a90b4)(puVar6,*(undefined4 *)(param_1 + 0x84));
  uVar2 = (*(code *)PTR_EVP_CIPHER_CTX_key_length_006a90b8)(*(undefined4 *)(param_1 + 0x80));
  (*(code *)PTR_EVP_DigestUpdate_006a8674)(puVar6,uVar13,uVar2);
  (*(code *)PTR_EVP_DigestUpdate_006a8674)(puVar6,uVar11,uVar12);
  (*(code *)PTR_EVP_DigestUpdate_006a8674)(puVar6,&local_28,4);
  uVar8 = 0;
  (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(puVar6);
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)();
  if (local_24 == *(uint *)puVar1) {
    return *(uint *)puVar1;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar4 = *(int *)(puVar6 + 0x54);
  puStack_88 = &_gp;
  iVar9 = *(int *)(iVar4 + 0x28);
  if ((int)param_2 <= iVar9) {
    if (param_4 == 0) {
      iVar5 = *(int *)(iVar4 + 0x2c);
      *(int *)(puVar6 + 0x4c) = *(int *)(iVar4 + 0x30) + iVar5;
      uVar8 = param_2;
    }
    else {
      iVar5 = *(int *)(iVar4 + 0x2c);
      uVar8 = param_2 + *(int *)(puVar6 + 0x50);
    }
    *(uint *)(puVar6 + 0x50) = uVar8;
    *(uint *)(iVar4 + 0x28) = iVar9 - param_2;
    *(uint *)(iVar4 + 0x2c) = param_2 + iVar5;
    return param_2;
  }
  if (*(int *)(puVar6 + 0x60) == 0) {
    uVar8 = param_2;
  }
  uVar10 = 0x8001;
  if (uVar8 < 0x8002) {
    uVar10 = uVar8;
  }
  if (iVar9 == 0) {
    iVar5 = *(int *)(puVar6 + 0x50);
    if ((iVar5 != 0) && (param_4 != 0)) goto LAB_0047d160;
    iVar5 = 0;
    *(undefined4 *)(puVar6 + 0x4c) = *(undefined4 *)(iVar4 + 0x30);
    if ((int)param_2 < 1) goto LAB_0047d19c;
  }
  else {
    if (param_4 == 0) {
      iVar7 = *(int *)(iVar4 + 0x30);
      if (*(int *)(iVar4 + 0x2c) != 0) {
        iVar5 = 0;
        (*(code *)PTR_memcpy_006aabf4)(iVar7,iVar7 + *(int *)(iVar4 + 0x2c),iVar9);
        iVar4 = *(int *)(puVar6 + 0x54);
        *(undefined4 *)(iVar4 + 0x2c) = 0;
        *(undefined4 *)(iVar4 + 0x28) = 0;
        *(undefined4 *)(puVar6 + 0x4c) = *(undefined4 *)(iVar4 + 0x30);
        goto LAB_0047d078;
      }
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(puVar6 + 0x50);
LAB_0047d160:
      iVar7 = *(int *)(iVar4 + 0x30);
      if (*(int *)(puVar6 + 0x4c) != iVar7) {
        (*(code *)PTR_memcpy_006aabf4)(iVar7,*(int *)(puVar6 + 0x4c),iVar9 + iVar5);
        iVar4 = *(int *)(puVar6 + 0x54);
        *(undefined4 *)(iVar4 + 0x28) = 0;
        *(undefined4 *)(puVar6 + 0x4c) = *(undefined4 *)(iVar4 + 0x30);
        goto LAB_0047d078;
      }
    }
    *(undefined4 *)(iVar4 + 0x28) = 0;
    *(int *)(puVar6 + 0x4c) = iVar7;
  }
LAB_0047d078:
  puVar3 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  do {
    iVar4 = *(int *)(puVar6 + 0xc);
    pcVar14 = *(code **)(puStack_88 + -0x7924);
    *puVar3 = 0;
    if (iVar4 == 0) {
      (**(code **)(puStack_88 + -0x6eb0))(0x14,0x70,0xd3,"s2_pkt.c",0x180);
      uVar8 = 0xffffffff;
LAB_0047d100:
      *(int *)(*(int *)(puVar6 + 0x54) + 0x28) = *(int *)(*(int *)(puVar6 + 0x54) + 0x28) + iVar9;
      return uVar8;
    }
    *(undefined4 *)(puVar6 + 0x18) = 3;
    uVar8 = (*pcVar14)(iVar4,*(int *)(*(int *)(puVar6 + 0x54) + 0x30) + iVar9 + iVar5,uVar10 - iVar9
                      );
    if ((int)uVar8 < 1) goto LAB_0047d100;
    iVar9 = iVar9 + uVar8;
  } while (iVar9 < (int)param_2);
  iVar4 = *(int *)(puVar6 + 0x54);
LAB_0047d19c:
  if ((int)param_2 < iVar9) {
    *(uint *)(iVar4 + 0x2c) = iVar5 + param_2;
    *(uint *)(iVar4 + 0x28) = iVar9 - param_2;
  }
  else {
    *(undefined4 *)(iVar4 + 0x2c) = 0;
    *(undefined4 *)(iVar4 + 0x28) = 0;
  }
  uVar8 = param_2;
  if (param_4 != 0) {
    uVar8 = param_2 + *(int *)(puVar6 + 0x50);
  }
  *(uint *)(puVar6 + 0x50) = uVar8;
  *(undefined4 *)(puVar6 + 0x18) = 1;
  return param_2;
}

