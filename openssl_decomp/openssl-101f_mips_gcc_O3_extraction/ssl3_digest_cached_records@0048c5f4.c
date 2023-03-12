
undefined4 ssl3_digest_cached_records(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint *puVar5;
  int *piVar6;
  int iVar7;
  uint *puVar8;
  char *pcVar9;
  int iVar10;
  undefined4 *unaff_s5;
  uint *unaff_s6;
  undefined *puVar11;
  undefined4 uStack_dc;
  uint uStack_d8;
  undefined auStack_d4 [24];
  undefined auStack_bc [64];
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  char *pcStack_70;
  undefined *puStack_6c;
  int iStack_68;
  undefined4 *puStack_64;
  uint *puStack_60;
  code *pcStack_5c;
  undefined4 local_48;
  undefined *local_40;
  uint local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  
  puStack_6c = PTR___stack_chk_guard_006aabf0;
  puVar11 = &_gp;
  iStack_78 = *(int *)(param_1 + 0x58);
  local_40 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  piVar1 = *(int **)(iStack_78 + 0x17c);
  if (piVar1 != (int *)0x0) {
    iVar10 = 0;
    piVar6 = piVar1;
    do {
      if (*piVar6 != 0) {
        (**(code **)(puVar11 + -0x6d18))();
        piVar1 = *(int **)(*(int *)(param_1 + 0x58) + 0x17c);
        puVar11 = local_40;
      }
      iVar10 = iVar10 + 4;
      piVar6 = (int *)((int)piVar1 + iVar10);
    } while (iVar10 != 0x18);
    (**(code **)(puVar11 + -0x7f58))(piVar1);
    iStack_78 = *(int *)(param_1 + 0x58);
    *(undefined4 *)(iStack_78 + 0x17c) = 0;
  }
  pcStack_70 = "s\n";
  uVar2 = (**(code **)(local_40 + -0x7dd8))(0x18,"s3_enc.c",0x256);
  iVar10 = *(int *)(param_1 + 0x58);
  *(undefined4 *)(iStack_78 + 0x17c) = uVar2;
  (**(code **)(local_40 + -0x53e0))(*(undefined4 *)(iVar10 + 0x17c),0,0x18);
  pcVar9 = (char *)&local_30;
  iStack_68 = (**(code **)(local_40 + -0x7fc8))
                        (*(undefined4 *)(*(int *)(param_1 + 0x58) + 0x178),3,0,pcVar9);
  if (iStack_68 < 1) {
    pcVar9 = "s3_enc.c";
    piVar1 = (int *)0x14c;
    puVar8 = (uint *)0x125;
    local_48 = 0x25b;
    (**(code **)(local_40 + -0x6eb0))(0x14,0x125,0x14c,"s3_enc.c");
    uVar2 = 0;
  }
  else {
    pcStack_70 = (char *)0x0;
    unaff_s6 = &local_38;
    puVar8 = unaff_s6;
    piVar1 = &local_34;
    iVar10 = (**(code **)(local_40 + -0x6cbc))(0);
    iStack_78 = 0;
    while (iVar10 != 0) {
      uVar3 = ssl_get_algorithm2(param_1);
      if (((uVar3 & local_38) == 0) || (local_34 == 0)) {
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iStack_78) = 0;
      }
      else {
        iVar10 = *(int *)(*(int *)(param_1 + 0x58) + 0x17c);
        uVar2 = (**(code **)(local_40 + -0x6d1c))();
        unaff_s5 = (undefined4 *)(iVar10 + iStack_78);
        *unaff_s5 = uVar2;
        (**(code **)(local_40 + -0x7870))
                  (*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iStack_78),local_34,
                   0);
        (**(code **)(local_40 + -0x786c))
                  (*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iStack_78),local_30,
                   iStack_68);
      }
      pcStack_70 = pcStack_70 + 1;
      iStack_78 = iStack_78 + 4;
      puVar8 = unaff_s6;
      piVar1 = &local_34;
      iVar10 = (**(code **)(local_40 + -0x6cbc))(pcStack_70);
    }
    if ((**(uint **)(param_1 + 0x58) & 0x20) == 0) {
      (**(code **)(local_40 + -0x7f70))((*(uint **)(param_1 + 0x58))[0x5e]);
      uVar2 = 1;
      *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x178) = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  if (local_2c == *(int *)puStack_6c) {
    return uVar2;
  }
  pcStack_5c = ssl3_handshake_mac;
  iVar10 = local_2c;
  (**(code **)(local_40 + -0x5328))();
  uVar2 = local_48;
  puVar11 = PTR___stack_chk_guard_006aabf0;
  iVar7 = *(int *)(iVar10 + 0x58);
  iStack_7c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_74 = param_1;
  puStack_64 = unaff_s5;
  puStack_60 = unaff_s6;
  if (*(int *)(iVar7 + 0x178) != 0) {
    iVar7 = ssl3_digest_cached_records();
    if (iVar7 == 0) goto LAB_0048c988;
    iVar7 = *(int *)(iVar10 + 0x58);
  }
  uStack_d8 = 0;
LAB_0048c914:
  if (*(int *)(*(int *)(iVar7 + 0x17c) + uStack_d8 * 4) != 0) {
    uVar4 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)();
    puVar5 = (uint *)(*(code *)PTR_EVP_MD_type_006a84cc)(uVar4);
    if (puVar5 == puVar8) {
      iVar7 = *(int *)(*(int *)(*(int *)(iVar10 + 0x58) + 0x17c) + uStack_d8 * 4);
      if (iVar7 != 0) {
        (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_d4);
        (*(code *)PTR_EVP_MD_CTX_set_flags_006a8600)(auStack_d4,8);
        (*(code *)PTR_EVP_MD_CTX_copy_ex_006a922c)(auStack_d4,iVar7);
        uVar4 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(auStack_d4);
        iVar7 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar4);
        if (iVar7 < 0) goto LAB_0048c988;
        if (iVar7 == 0) {
          trap(7);
        }
        iVar7 = (0x30 / iVar7) * iVar7;
        if (piVar1 != (int *)0x0) {
          (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_d4,piVar1,pcVar9);
        }
        (*(code *)PTR_EVP_DigestUpdate_006a8674)
                  (auStack_d4,*(int *)(iVar10 + 0xc0) + 0x14,
                   *(undefined4 *)(*(int *)(iVar10 + 0xc0) + 0x10));
        (*(code *)PTR_EVP_DigestUpdate_006a8674)
                  (auStack_d4,"666666666666666666666666666666666666666666666666",iVar7);
        (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_d4,auStack_bc,&uStack_d8);
        uVar4 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(auStack_d4);
        (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_d4,uVar4,0);
        (*(code *)PTR_EVP_DigestUpdate_006a8674)
                  (auStack_d4,*(int *)(iVar10 + 0xc0) + 0x14,
                   *(undefined4 *)(*(int *)(iVar10 + 0xc0) + 0x10));
        (*(code *)PTR_EVP_DigestUpdate_006a8674)
                  (auStack_d4,
                   "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\666666666666666666666666666666666666666666666666"
                   ,iVar7);
        (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_d4,auStack_bc,uStack_d8);
        (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_d4,uVar2);
        (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_d4);
        goto LAB_0048c98c;
      }
LAB_0048c960:
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x11d,0x144,"s3_enc.c",0x2a3);
LAB_0048c988:
      uStack_dc = 0;
LAB_0048c98c:
      if (iStack_7c != *(int *)puVar11) {
        (*(code *)PTR___stack_chk_fail_006aabb8)();
        uVar2 = ssl3_handshake_mac();
        return uVar2;
      }
      return uStack_dc;
    }
  }
  uStack_d8 = uStack_d8 + 1;
  if (5 < uStack_d8) goto LAB_0048c960;
  iVar7 = *(int *)(iVar10 + 0x58);
  goto LAB_0048c914;
}

