
undefined4 ssl3_digest_cached_records(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint *puVar9;
  char *pcVar10;
  int iVar11;
  undefined4 *unaff_s5;
  uint *unaff_s6;
  undefined *puVar12;
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
  
  puStack_6c = PTR___stack_chk_guard_006a9ae8;
  puVar12 = &_gp;
  iStack_78 = *(int *)(param_1 + 0x58);
  local_40 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  piVar1 = *(int **)(iStack_78 + 0x17c);
  if (piVar1 != (int *)0x0) {
    iVar11 = 0;
    piVar7 = piVar1;
    do {
      if (*piVar7 != 0) {
        (**(code **)(puVar12 + -0x6d58))();
        piVar1 = *(int **)(*(int *)(param_1 + 0x58) + 0x17c);
        puVar12 = local_40;
      }
      iVar11 = iVar11 + 4;
      piVar7 = (int *)((int)piVar1 + iVar11);
    } while (iVar11 != 0x18);
    (**(code **)(puVar12 + -0x7f58))(piVar1);
    iStack_78 = *(int *)(param_1 + 0x58);
    *(undefined4 *)(iStack_78 + 0x17c) = 0;
  }
  pcStack_70 = "-check_ss_sig";
  uVar2 = (**(code **)(local_40 + -0x7dd8))(0x18,"s3_enc.c",0x250);
  iVar11 = *(int *)(param_1 + 0x58);
  *(undefined4 *)(iStack_78 + 0x17c) = uVar2;
  (**(code **)(local_40 + -0x53ec))(*(undefined4 *)(iVar11 + 0x17c),0,0x18);
  pcVar10 = (char *)&local_30;
  iStack_68 = (**(code **)(local_40 + -0x7fc8))
                        (*(undefined4 *)(*(int *)(param_1 + 0x58) + 0x178),3,0,pcVar10);
  if (iStack_68 < 1) {
    pcVar10 = "s3_enc.c";
    piVar1 = (int *)0x14c;
    puVar9 = (uint *)0x125;
    local_48 = 0x254;
    (**(code **)(local_40 + -0x6eac))(0x14,0x125,0x14c,"s3_enc.c");
    uVar2 = 0;
  }
  else {
    pcStack_70 = (char *)0x0;
    unaff_s6 = &local_38;
    puVar9 = unaff_s6;
    piVar1 = &local_34;
    iVar11 = (**(code **)(local_40 + -0x6ce4))(0);
    iStack_78 = 0;
    while (iVar11 != 0) {
      uVar3 = ssl_get_algorithm2(param_1);
      if (((uVar3 & local_38) == 0) || (local_34 == 0)) {
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iStack_78) = 0;
      }
      else {
        iVar11 = *(int *)(*(int *)(param_1 + 0x58) + 0x17c);
        uVar2 = (**(code **)(local_40 + -0x6d5c))();
        unaff_s5 = (undefined4 *)(iVar11 + iStack_78);
        *unaff_s5 = uVar2;
        (**(code **)(local_40 + -0x7864))
                  (*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iStack_78),local_34,
                   0);
        (**(code **)(local_40 + -0x7860))
                  (*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iStack_78),local_30,
                   iStack_68);
      }
      pcStack_70 = pcStack_70 + 1;
      iStack_78 = iStack_78 + 4;
      puVar9 = unaff_s6;
      piVar1 = &local_34;
      iVar11 = (**(code **)(local_40 + -0x6ce4))(pcStack_70);
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
  iVar11 = local_2c;
  (**(code **)(local_40 + -0x5330))();
  uVar2 = local_48;
  puVar12 = PTR___stack_chk_guard_006a9ae8;
  iVar8 = *(int *)(iVar11 + 0x58);
  iStack_7c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_74 = param_1;
  puStack_64 = unaff_s5;
  puStack_60 = unaff_s6;
  if (*(int *)(iVar8 + 0x178) != 0) {
    iVar8 = ssl3_digest_cached_records();
    if (iVar8 == 0) goto LAB_0048888c;
    iVar8 = *(int *)(iVar11 + 0x58);
  }
  uStack_d8 = 0;
LAB_00488818:
  if (*(int *)(*(int *)(iVar8 + 0x17c) + uStack_d8 * 4) != 0) {
    uVar4 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)();
    puVar5 = (uint *)(*(code *)PTR_EVP_MD_type_006a73cc)(uVar4);
    if (puVar5 == puVar9) {
      iVar8 = *(int *)(*(int *)(*(int *)(iVar11 + 0x58) + 0x17c) + uStack_d8 * 4);
      if (iVar8 != 0) {
        (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_d4);
        (*(code *)PTR_EVP_MD_CTX_set_flags_006a7504)(auStack_d4,8);
        (*(code *)PTR_EVP_MD_CTX_copy_ex_006a8104)(auStack_d4,iVar8);
        uVar4 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(auStack_d4);
        iVar8 = (*(code *)PTR_EVP_MD_size_006a7e3c)(uVar4);
        if (iVar8 < 0) goto LAB_0048888c;
        if (((piVar1 == (int *)0x0) ||
            (iVar6 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_d4,piVar1,pcVar10), 0 < iVar6)
            ) && (iVar6 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                                    (auStack_d4,*(int *)(iVar11 + 0xc0) + 0x14,
                                     *(undefined4 *)(*(int *)(iVar11 + 0xc0) + 0x10)), 0 < iVar6)) {
          if (iVar8 == 0) {
            trap(7);
          }
          iVar8 = (0x30 / iVar8) * iVar8;
          iVar6 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                            (auStack_d4,"666666666666666666666666666666666666666666666666",iVar8);
          if (iVar6 < 1) goto LAB_00488a7c;
          iVar6 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_d4,auStack_bc,&uStack_d8);
          if (iVar6 < 1) goto LAB_00488a7c;
          uVar4 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(auStack_d4);
          iVar6 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_d4,uVar4,0);
          if (((iVar6 < 1) ||
              (iVar11 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                                  (auStack_d4,*(int *)(iVar11 + 0xc0) + 0x14,
                                   *(undefined4 *)(*(int *)(iVar11 + 0xc0) + 0x10)), iVar11 < 1)) ||
             ((iVar11 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                                  (auStack_d4,
                                   "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\666666666666666666666666666666666666666666666666"
                                   ,iVar8), iVar11 < 1 ||
              ((iVar11 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_d4,auStack_bc,uStack_d8),
               iVar11 < 1 ||
               (iVar11 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_d4,uVar2), iVar11 < 1)))
              ))) goto LAB_00488a7c;
        }
        else {
LAB_00488a7c:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x11d,0x44,"s3_enc.c",0x2b7);
          uStack_dc = 0;
        }
        (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_d4);
        goto LAB_00488890;
      }
LAB_00488864:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x11d,0x144,"s3_enc.c",0x2a0);
LAB_0048888c:
      uStack_dc = 0;
LAB_00488890:
      if (iStack_7c != *(int *)puVar12) {
        (*(code *)PTR___stack_chk_fail_006a9ab0)();
        uVar2 = ssl3_handshake_mac();
        return uVar2;
      }
      return uStack_dc;
    }
  }
  uStack_d8 = uStack_d8 + 1;
  if (5 < uStack_d8) goto LAB_00488864;
  iVar8 = *(int *)(iVar11 + 0x58);
  goto LAB_00488818;
}

