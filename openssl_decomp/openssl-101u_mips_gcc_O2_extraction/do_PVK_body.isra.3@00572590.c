
undefined4 **
do_PVK_body_isra_3(undefined4 *param_1,undefined4 **param_2,uint param_3,undefined4 *param_4,
                  undefined4 **param_5)

{
  char cVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  char *pcVar5;
  undefined4 **ppuVar6;
  undefined4 **ppuVar7;
  undefined4 **ppuVar8;
  uint uVar9;
  undefined4 **ppuVar10;
  int iVar11;
  undefined4 **ppuVar12;
  char *pcVar13;
  char *pcVar14;
  char **ppcVar15;
  uint uVar16;
  undefined4 **ppuVar17;
  uint uVar18;
  undefined4 uVar19;
  int iVar20;
  int iVar21;
  undefined4 **ppuVar22;
  undefined4 *puVar23;
  undefined4 *puVar24;
  undefined4 **unaff_s7;
  char *pcVar25;
  code *pcVar26;
  undefined4 *unaff_s8;
  undefined4 *puVar27;
  undefined4 *puStack_668;
  int iStack_664;
  undefined4 **ppuStack_660;
  undefined *puStack_65c;
  undefined4 **ppuStack_658;
  undefined4 *puStack_654;
  undefined4 **ppuStack_650;
  undefined4 **ppuStack_64c;
  undefined4 *puStack_648;
  undefined4 **ppuStack_644;
  undefined4 *puStack_640;
  code *pcStack_63c;
  undefined4 uStack_628;
  undefined *puStack_620;
  undefined4 **ppuStack_618;
  char cStack_614;
  char cStack_613;
  uint uStack_60c;
  uint uStack_608;
  undefined4 *puStack_604;
  undefined4 **ppuStack_600;
  undefined *puStack_5fc;
  undefined4 **ppuStack_5f8;
  undefined *puStack_5f4;
  undefined4 **ppuStack_5f0;
  undefined4 **ppuStack_5ec;
  undefined4 *puStack_5e8;
  code *pcStack_5e4;
  undefined4 uStack_5d0;
  undefined *puStack_5c8;
  undefined4 **ppuStack_5c0;
  char cStack_5bc;
  char cStack_5bb;
  uint uStack_5b4;
  uint uStack_5b0;
  undefined4 *puStack_5ac;
  undefined *puStack_5a8;
  undefined4 **ppuStack_5a4;
  uint uStack_5a0;
  undefined *puStack_59c;
  undefined4 **ppuStack_598;
  undefined4 **ppuStack_594;
  undefined *puStack_590;
  code *pcStack_58c;
  undefined4 uStack_578;
  undefined *puStack_570;
  char *pcStack_568;
  undefined4 **ppuStack_564;
  undefined *puStack_55c;
  undefined4 **ppuStack_558;
  code *pcStack_554;
  undefined4 uStack_540;
  undefined *puStack_538;
  char *pcStack_530;
  char **ppcStack_52c;
  undefined4 *puStack_524;
  undefined4 **ppuStack_520;
  code *pcStack_51c;
  int local_508;
  undefined *local_500;
  undefined4 *local_4f4;
  uint local_4f0;
  uint local_4ec;
  undefined4 *local_4e4 [6];
  undefined auStack_4cc [140];
  undefined4 uStack_440;
  undefined local_43b;
  undefined local_43a;
  undefined local_439;
  undefined local_438;
  undefined local_437;
  undefined local_436;
  undefined local_435;
  undefined local_434;
  undefined local_433;
  undefined local_432;
  undefined local_431;
  undefined4 auStack_42c [256];
  char **local_2c;
  
  puVar24 = (undefined4 *)PTR___stack_chk_guard_006a9ae8;
  puStack_5f4 = auStack_4cc;
  local_500 = &_gp;
  local_2c = *(char ***)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_EVP_CIPHER_CTX_init_006a7a64)(puStack_5f4);
  if (param_2 == (undefined4 **)0x0) {
    param_4 = (undefined4 *)0x0;
    local_4e4[0] = param_1;
    if (param_3 < 0x10) {
LAB_0057297c:
      puVar3 = (undefined4 *)&DAT_00000084;
      local_508 = 0xf8;
      ppuStack_5a4 = (undefined4 **)0x0;
      (**(code **)(local_500 + -0x6eac))(9,0x84,0x7a,FUN_0066c47c);
    }
    else {
LAB_005729d8:
      if (*(char *)local_4e4[0] == '\x06') {
        pcVar26 = *(code **)(local_500 + -0x6eac);
        uVar19 = 0x77;
        local_508 = 0x9d;
LAB_00572af4:
        (*pcVar26)(9,0x86,uVar19,FUN_0066c47c);
        goto LAB_0057297c;
      }
      if (*(char *)local_4e4[0] != '\a') goto LAB_0057297c;
      if (*(char *)((int)local_4e4[0] + 1) != '\x02') {
        pcVar26 = *(code **)(local_500 + -0x6eac);
        uVar19 = 0x75;
        local_508 = 0xac;
        goto LAB_00572af4;
      }
      puVar27 = local_4e4[0] + 4;
      uVar9 = (uint)*(byte *)((int)local_4e4[0] + 9) << 8 |
              (uint)*(byte *)((int)local_4e4[0] + 10) << 0x10 | (uint)*(byte *)(local_4e4[0] + 2) |
              (uint)*(byte *)((int)local_4e4[0] + 0xb) << 0x18;
      puVar3 = (undefined4 *)
               ((uint)*(byte *)((int)local_4e4[0] + 0xd) << 8 |
                (uint)*(byte *)((int)local_4e4[0] + 0xe) << 0x10 | (uint)*(byte *)(local_4e4[0] + 3)
               | (uint)*(byte *)((int)local_4e4[0] + 0xf) << 0x18);
      if (uVar9 == 0x31535344) {
LAB_00572b20:
        pcVar26 = *(code **)(local_500 + -0x6eac);
        uVar19 = 0x77;
        local_508 = 0xba;
        goto LAB_00572af4;
      }
      if (uVar9 < 0x31535345) {
        if (uVar9 != 0x31415352) {
          pcVar26 = *(code **)(local_500 + -0x6eac);
LAB_00572c78:
          uVar19 = 0x74;
          local_508 = 0xc9;
          goto LAB_00572af4;
        }
        goto LAB_00572b20;
      }
      if (uVar9 == 0x32415352) {
        param_3 = param_3 - 0x10;
        if (param_3 < (((uint)((int)puVar3 + 7) >> 3) + 2) * 2 +
                      ((uint)((int)puVar3 + 0xf) >> 4) * 5) {
LAB_00572c28:
          local_508 = 0xfd;
          puVar3 = (undefined4 *)&DAT_00000084;
          ppuStack_5a4 = (undefined4 **)0x0;
          local_4e4[0] = puVar27;
          (**(code **)(local_500 + -0x6eac))(9,0x84,0x7b,FUN_0066c47c);
        }
        else {
          local_4e4[0] = puVar27;
          ppuStack_5a4 = (undefined4 **)b2i_rsa_isra_1(local_4e4,puVar3,0);
        }
      }
      else {
        pcVar26 = *(code **)(local_500 + -0x6eac);
        if (uVar9 != 0x32535344) goto LAB_00572c78;
        param_3 = (uint)(param_3 - 0x10 < (((uint)((int)puVar3 + 7) >> 3) + 0x20) * 2);
        if (param_3 != 0) goto LAB_00572c28;
        local_4e4[0] = puVar27;
        ppuStack_5a4 = (undefined4 **)b2i_dss_isra_0(local_4e4,puVar3,0);
      }
    }
    unaff_s7 = (undefined4 **)0x670000;
    (**(code **)(local_500 + -0x736c))(puStack_5f4);
    if ((param_4 != (undefined4 *)0x0) &&
       (pcVar26 = *(code **)(local_500 + -0x7f58), param_2 != (undefined4 **)0x0)) {
LAB_005726c0:
      unaff_s7 = (undefined4 **)0x670000;
      (*pcVar26)(param_4);
    }
  }
  else {
    local_4f4 = auStack_42c;
    if (param_4 == (undefined4 *)0x0) {
      unaff_s8 = (undefined4 *)PEM_def_callback((char *)local_4f4,0x400,0,param_5);
    }
    else {
      unaff_s8 = (undefined4 *)(*(code *)param_4)(local_4f4,0x400,0,param_5);
    }
    if ((int)unaff_s8 < 1) {
      local_508 = 0x2c2;
      puVar3 = (undefined4 *)0x87;
      (**(code **)(local_500 + -0x6eac))(9,0x87,0x68,FUN_0066c47c);
    }
    else {
      unaff_s7 = (undefined4 **)0x670000;
      param_4 = (undefined4 *)(**(code **)(local_500 + -0x7dd8))(param_3 + 8,FUN_0066c47c,0x2c5);
      if (param_4 != (undefined4 *)0x0) {
        param_5 = local_4e4;
        (**(code **)(local_500 + -0x7fc4))(param_5);
        puVar3 = (undefined4 *)(**(code **)(local_500 + -0x7810))();
        iVar4 = (**(code **)(local_500 + -0x7864))(param_5,puVar3,0);
        if (((iVar4 == 0) ||
            (puVar3 = param_1, iVar4 = (**(code **)(local_500 + -0x7860))(param_5,param_1,param_2),
            iVar4 == 0)) ||
           (puVar3 = local_4f4,
           iVar4 = (**(code **)(local_500 + -0x7860))(param_5,local_4f4,unaff_s8), iVar4 == 0)) {
LAB_00572698:
          (**(code **)(local_500 + -0x7fac))(param_5);
        }
        else {
          puVar3 = &uStack_440;
          local_4f4 = puVar3;
          iVar4 = (**(code **)(local_500 + -0x785c))(param_5,puVar3,0);
          if (iVar4 == 0) goto LAB_00572698;
          param_1 = (undefined4 *)((int)param_1 + (int)param_2);
          (**(code **)(local_500 + -0x7fac))(param_5);
          uVar19 = param_1[1];
          *param_4 = *param_1;
          param_4[1] = uVar19;
          if (param_3 < 8) {
            puVar3 = (undefined4 *)0x87;
            local_508 = 0x2d2;
            (**(code **)(local_500 + -0x6eac))(9,0x87,0x7d,FUN_0066c47c);
          }
          else {
            local_4f0 = param_3 - 8;
            unaff_s8 = param_4 + 2;
            puVar3 = (undefined4 *)(**(code **)(local_500 + -0x69d8))();
            local_508 = 0;
            iVar4 = (**(code **)(local_500 + -0x7378))(puStack_5f4,puVar3,0,local_4f4);
            if (iVar4 != 0) {
              local_508 = param_3 - 8;
              puVar3 = unaff_s8;
              iVar4 = (**(code **)(local_500 + -0x7370))(puStack_5f4,unaff_s8,param_5,param_1 + 2);
              if (iVar4 != 0) {
                puVar3 = (undefined4 *)((int)unaff_s8 + (int)local_4e4[0]);
                iVar4 = (**(code **)(local_500 + -0x7374))(puStack_5f4,puVar3,param_5);
                if (iVar4 != 0) {
                  uVar9 = (uint)*(byte *)((int)param_4 + 9) << 8 |
                          (uint)*(byte *)((int)param_4 + 10) << 0x10 | (uint)*(byte *)(param_4 + 2)
                          | (uint)*(byte *)((int)param_4 + 0xb) << 0x18;
                  local_4f0 = 0x32415352;
                  if ((uVar9 == 0x32415352) || (local_4ec = 0x32535344, uVar9 == 0x32535344)) {
                    (**(code **)(local_500 + -0x7d6c))(local_4f4,0x14);
LAB_0057296c:
                    local_4e4[0] = param_4;
                    if (0xf < param_3) goto LAB_005729d8;
                    goto LAB_0057297c;
                  }
                  local_43b = 0;
                  local_43a = 0;
                  local_439 = 0;
                  local_438 = 0;
                  local_437 = 0;
                  local_436 = 0;
                  local_435 = 0;
                  local_434 = 0;
                  local_433 = 0;
                  local_432 = 0;
                  local_431 = 0;
                  puVar3 = (undefined4 *)(**(code **)(local_500 + -0x69d8))();
                  local_508 = 0;
                  iVar4 = (**(code **)(local_500 + -0x7378))(puStack_5f4,puVar3,0,local_4f4);
                  if (iVar4 != 0) {
                    (**(code **)(local_500 + -0x7d6c))(local_4f4,0x14);
                    local_508 = param_3 - 8;
                    puVar3 = unaff_s8;
                    iVar4 = (**(code **)(local_500 + -0x7370))
                                      (puStack_5f4,unaff_s8,param_5,param_1 + 2);
                    if (iVar4 != 0) {
                      puVar3 = (undefined4 *)((int)unaff_s8 + (int)local_4e4[0]);
                      iVar4 = (**(code **)(local_500 + -0x7374))(puStack_5f4,puVar3,param_5);
                      if (iVar4 != 0) {
                        uVar9 = (uint)*(byte *)((int)param_4 + 9) << 8 |
                                (uint)*(byte *)((int)param_4 + 10) << 0x10 |
                                (uint)*(byte *)(param_4 + 2) |
                                (uint)*(byte *)((int)param_4 + 0xb) << 0x18;
                        if ((uVar9 == local_4f0) || (uVar9 == local_4ec)) goto LAB_0057296c;
                        puVar3 = (undefined4 *)0x87;
                        local_508 = 0x2ea;
                        (**(code **)(local_500 + -0x6eac))(9,0x87,0x65,FUN_0066c47c);
                      }
                    }
                  }
                }
              }
            }
          }
        }
        ppuStack_5a4 = (undefined4 **)0x0;
        (**(code **)(local_500 + -0x736c))(puStack_5f4);
        pcVar26 = *(code **)(local_500 + -0x7f58);
        goto LAB_005726c0;
      }
      puVar3 = (undefined4 *)0x87;
      local_508 = 0x2c7;
      (**(code **)(local_500 + -0x6eac))(9,0x87,0x41,FUN_0066c47c);
    }
    ppuStack_5a4 = (undefined4 **)0x0;
    (**(code **)(local_500 + -0x736c))(puStack_5f4);
  }
  if (local_2c == (char **)*puVar24) {
    return ppuStack_5a4;
  }
  pcStack_51c = b2i_PrivateKey;
  ppcVar15 = local_2c;
  (**(code **)(local_500 + -0x5330))();
  puStack_55c = PTR___stack_chk_guard_006a9ae8;
  pcVar5 = *ppcVar15;
  puStack_538 = &_gp;
  ppcStack_52c = *(char ***)PTR___stack_chk_guard_006a9ae8;
  pcStack_530 = pcVar5;
  puStack_524 = param_4;
  ppuStack_520 = ppuStack_5a4;
  if (puVar3 < &SUB_00000010) {
LAB_00572d10:
    ppuStack_5a4 = (undefined4 **)0x670000;
    uVar16 = 0x84;
    uStack_540 = 0xf8;
    (**(code **)(puStack_538 + -0x6eac))(9,0x84,0x7a,FUN_0066c47c);
    ppuVar6 = (undefined4 **)0x0;
  }
  else {
    if (*pcVar5 == '\x06') {
      uVar19 = 0x77;
      uStack_540 = 0x9d;
LAB_00572e30:
      pcStack_530 = pcVar5;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x86,uVar19,FUN_0066c47c);
      goto LAB_00572d10;
    }
    if (*pcVar5 != '\a') goto LAB_00572d10;
    if (pcVar5[1] != '\x02') {
      uVar19 = 0x75;
      uStack_540 = 0xac;
      goto LAB_00572e30;
    }
    pcStack_530 = pcVar5 + 0x10;
    uVar9 = (uint)(byte)pcVar5[9] << 8 | (uint)(byte)pcVar5[10] << 0x10 | (uint)(byte)pcVar5[8] |
            (uint)(byte)pcVar5[0xb] << 0x18;
    uVar16 = (uint)(byte)pcVar5[0xd] << 8 | (uint)(byte)pcVar5[0xe] << 0x10 |
             (uint)(byte)pcVar5[0xc] | (uint)(byte)pcVar5[0xf] << 0x18;
    if (uVar9 == 0x31535344) {
LAB_00572ea4:
      uVar19 = 0x77;
      uStack_540 = 0xba;
      goto LAB_00572e30;
    }
    if (uVar9 < 0x31535345) {
      if (uVar9 != 0x31415352) {
LAB_00572ed4:
        uVar19 = 0x74;
        uStack_540 = 0xc9;
        goto LAB_00572e30;
      }
      goto LAB_00572ea4;
    }
    if (uVar9 == 0x32415352) {
      if (puVar3 + -4 < (undefined4 *)(((uVar16 + 7 >> 3) + 2) * 2 + (uVar16 + 0xf >> 4) * 5)) {
LAB_00572eec:
        uStack_540 = 0xfd;
        uVar16 = 0x84;
        (*(code *)PTR_ERR_put_error_006a7f34)(9,0x84,0x7b,FUN_0066c47c);
        ppuVar6 = (undefined4 **)0x0;
      }
      else {
        ppuVar6 = (undefined4 **)b2i_rsa_isra_1(&pcStack_530,uVar16,0);
      }
    }
    else {
      if (uVar9 != 0x32535344) goto LAB_00572ed4;
      if (puVar3 + -4 < (undefined4 *)(((uVar16 + 7 >> 3) + 0x20) * 2)) goto LAB_00572eec;
      ppuVar6 = (undefined4 **)b2i_dss_isra_0(&pcStack_530,uVar16,0);
    }
  }
  if (ppcStack_52c == *(char ***)puStack_55c) {
    return ppuVar6;
  }
  pcStack_554 = b2i_PublicKey;
  ppcVar15 = ppcStack_52c;
  (**(code **)(puStack_538 + -0x5330))();
  puStack_5a8 = PTR___stack_chk_guard_006a9ae8;
  pcVar5 = *ppcVar15;
  puStack_570 = &_gp;
  ppuStack_564 = *(undefined4 ***)PTR___stack_chk_guard_006a9ae8;
  pcStack_568 = pcVar5;
  ppuStack_558 = ppuStack_5a4;
  if (uVar16 < 0x10) {
LAB_00572f80:
    ppuStack_5a4 = (undefined4 **)0x670000;
    uStack_578 = 0xf8;
    (**(code **)(puStack_570 + -0x6eac))(9,0x84,0x7a,FUN_0066c47c);
    ppuVar6 = (undefined4 **)0x0;
  }
  else {
    if (*pcVar5 != '\x06') {
      if (*pcVar5 == '\a') {
        uVar19 = 0x78;
        uStack_578 = 0xa3;
        goto LAB_00573088;
      }
      goto LAB_00572f80;
    }
    if (pcVar5[1] != '\x02') {
      uVar19 = 0x75;
      uStack_578 = 0xac;
LAB_00573088:
      pcStack_568 = pcVar5;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x86,uVar19,FUN_0066c47c);
      goto LAB_00572f80;
    }
    pcStack_568 = pcVar5 + 0x10;
    uVar9 = (uint)(byte)pcVar5[9] << 8 | (uint)(byte)pcVar5[10] << 0x10 | (uint)(byte)pcVar5[8] |
            (uint)(byte)pcVar5[0xb] << 0x18;
    uVar18 = (uint)(byte)pcVar5[0xd] << 8 | (uint)(byte)pcVar5[0xe] << 0x10 |
             (uint)(byte)pcVar5[0xc] | (uint)(byte)pcVar5[0xf] << 0x18;
    if (uVar9 != 0x31535344) {
      if (uVar9 < 0x31535345) {
        if (uVar9 == 0x31415352) {
          if (uVar16 - 0x10 < (uVar18 + 7 >> 3) + 4) goto LAB_00573148;
          ppuVar6 = (undefined4 **)b2i_rsa_isra_1(&pcStack_568,uVar18,1);
          goto LAB_00572fa8;
        }
      }
      else if ((uVar9 == 0x32415352) || (uVar9 == 0x32535344)) {
        uVar19 = 0x78;
        uStack_578 = 0xc3;
        goto LAB_00573088;
      }
      uVar19 = 0x74;
      uStack_578 = 0xc9;
      goto LAB_00573088;
    }
    if (uVar16 - 0x10 < (uVar18 + 7 >> 3) * 3 + 0x2c) {
LAB_00573148:
      uStack_578 = 0xfd;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x84,0x7b,FUN_0066c47c);
      ppuVar6 = (undefined4 **)0x0;
    }
    else {
      ppuVar6 = (undefined4 **)b2i_dss_isra_0(&pcStack_568,uVar18,1);
    }
  }
LAB_00572fa8:
  if (ppuStack_564 == *(undefined4 ***)puStack_5a8) {
    return ppuVar6;
  }
  pcStack_58c = b2i_PrivateKey_bio;
  ppuVar6 = ppuStack_564;
  (**(code **)(puStack_570 + -0x5330))();
  puStack_5fc = PTR___stack_chk_guard_006a9ae8;
  ppuStack_600 = (undefined4 **)&cStack_5bc;
  puStack_5c8 = &_gp;
  puStack_590 = (undefined *)puVar24;
  puStack_5ac = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  uStack_5a0 = param_3;
  puStack_59c = puStack_5f4;
  ppuStack_598 = param_5;
  ppuStack_594 = param_2;
  iVar4 = (*(code *)PTR_BIO_read_006a74c0)();
  if (iVar4 == 0x10) {
    ppuStack_5c0 = ppuStack_600;
    if (cStack_5bc == '\x06') {
      pcVar26 = *(code **)(puStack_5c8 + -0x6eac);
      uVar19 = 0x77;
      uStack_5d0 = 0x9d;
LAB_0057338c:
      (*pcVar26)(9,0x86,uVar19,FUN_0066c47c);
      goto LAB_00573204;
    }
    if (cStack_5bc != '\a') goto LAB_00573204;
    if (cStack_5bb != '\x02') {
      pcVar26 = *(code **)(puStack_5c8 + -0x6eac);
      uVar19 = 0x75;
      uStack_5d0 = 0xac;
      goto LAB_0057338c;
    }
    uVar9 = (((uStack_5b4 >> 0x10) << 0x18 | (uStack_5b4 >> 0x18) << 0x10) >> 0x10) +
            ((uStack_5b4 & 0xff) << 8 | uStack_5b4 >> 8 & 0xff) * 0x10000;
    param_2 = (undefined4 **)
              ((((uStack_5b0 >> 0x10) << 0x18 | (uStack_5b0 >> 0x18) << 0x10) >> 0x10) +
              ((uStack_5b0 & 0xff) << 8 | uStack_5b0 >> 8 & 0xff) * 0x10000);
    if (uVar9 == 0x31535344) {
LAB_00573378:
      pcVar26 = *(code **)(puStack_5c8 + -0x6eac);
      uVar19 = 0x77;
      uStack_5d0 = 0xba;
      goto LAB_0057338c;
    }
    if (uVar9 < 0x31535345) {
      if (uVar9 != 0x31415352) {
LAB_00573470:
        pcVar26 = *(code **)(puStack_5c8 + -0x6eac);
        uVar19 = 0x74;
        uStack_5d0 = 0xc9;
        goto LAB_0057338c;
      }
      goto LAB_00573378;
    }
    if (uVar9 == 0x32415352) {
      puStack_5f4 = (undefined *)0x0;
      ppuStack_600 = (undefined4 **)
                     ((((uint)((int)param_2 + 7) >> 3) + 2) * 2 +
                     ((uint)((int)param_2 + 0xf) >> 4) * 5);
    }
    else {
      puStack_5f4 = (undefined *)0x1;
      if (uVar9 != 0x32535344) goto LAB_00573470;
      ppuStack_600 = (undefined4 **)((((uint)((int)param_2 + 7) >> 3) + 0x20) * 2);
    }
    ppuStack_5c0 = &puStack_5ac;
    puVar24 = (undefined4 *)0x670000;
    if ((undefined4 **)0x19000 < ppuStack_600) {
      pcVar26 = *(code **)(puStack_5c8 + -0x6eac);
      uVar19 = 0x80;
      uStack_5d0 = 0x117;
      goto LAB_00573350;
    }
    param_5 = (undefined4 **)(**(code **)(puStack_5c8 + -0x7dd8))(ppuStack_600,FUN_0066c47c,0x11a);
    if (param_5 == (undefined4 **)0x0) {
      uStack_5d0 = 0x11c;
      (**(code **)(puStack_5c8 + -0x6eac))(9,0x85,0x41,FUN_0066c47c);
      ppuVar7 = (undefined4 **)0x0;
    }
    else {
      ppuStack_5c0 = param_5;
      ppuVar7 = (undefined4 **)(**(code **)(puStack_5c8 + -0x7920))(ppuVar6,param_5,ppuStack_600);
      if (ppuStack_600 == ppuVar7) {
        if (puStack_5f4 == (undefined *)0x0) {
          ppuVar7 = (undefined4 **)b2i_rsa_isra_1(&ppuStack_5c0,param_2,0);
        }
        else {
          ppuVar7 = (undefined4 **)b2i_dss_isra_0();
        }
      }
      else {
        uStack_5d0 = 0x121;
        ppuVar7 = (undefined4 **)0x0;
        (**(code **)(puStack_5c8 + -0x6eac))(9,0x85,0x7b,FUN_0066c47c);
      }
      (**(code **)(puStack_5c8 + -0x7f58))(param_5);
      ppuStack_600 = ppuVar7;
    }
  }
  else {
    pcVar26 = *(code **)(puStack_5c8 + -0x6eac);
    uVar19 = 0x7b;
    uStack_5d0 = 0x10e;
LAB_00573350:
    (*pcVar26)(9,0x85,uVar19,FUN_0066c47c);
LAB_00573204:
    ppuVar7 = (undefined4 **)0x0;
  }
  if (puStack_5ac == *(undefined4 **)puStack_5fc) {
    return ppuVar7;
  }
  pcStack_5e4 = b2i_PublicKey_bio;
  puStack_654 = puStack_5ac;
  (**(code **)(puStack_5c8 + -0x5330))();
  ppuVar7 = (undefined4 **)PTR___stack_chk_guard_006a9ae8;
  ppuVar17 = (undefined4 **)&SUB_00000010;
  ppuVar10 = (undefined4 **)&cStack_614;
  puStack_620 = &_gp;
  puStack_604 = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  ppuVar22 = ppuVar10;
  ppuStack_5f8 = ppuVar6;
  ppuStack_5f0 = param_5;
  ppuStack_5ec = param_2;
  puStack_5e8 = puVar24;
  iVar4 = (*(code *)PTR_BIO_read_006a74c0)();
  if (iVar4 == 0x10) {
    ppuStack_618 = ppuVar10;
    if (cStack_614 != '\x06') {
      if (cStack_614 == '\a') {
        pcVar26 = *(code **)(puStack_620 + -0x6eac);
        ppuVar17 = (undefined4 **)&DAT_00000078;
        uStack_628 = 0xa3;
        goto LAB_005735cc;
      }
      goto LAB_00573528;
    }
    if (cStack_613 != '\x02') {
      pcVar26 = *(code **)(puStack_620 + -0x6eac);
      ppuVar17 = (undefined4 **)0x75;
      uStack_628 = 0xac;
LAB_005735cc:
      ppuVar22 = (undefined4 **)0x86;
      (*pcVar26)(9,0x86,ppuVar17,FUN_0066c47c);
      goto LAB_00573528;
    }
    uVar9 = (((uStack_60c >> 0x10) << 0x18 | (uStack_60c >> 0x18) << 0x10) >> 0x10) +
            ((uStack_60c & 0xff) << 8 | uStack_60c >> 8 & 0xff) * 0x10000;
    ppuVar6 = (undefined4 **)
              ((((uStack_608 >> 0x10) << 0x18 | (uStack_608 >> 0x18) << 0x10) >> 0x10) +
              ((uStack_608 & 0xff) << 8 | uStack_608 >> 8 & 0xff) * 0x10000);
    if (uVar9 != 0x31535344) {
      if (uVar9 < 0x31535345) {
        param_5 = (undefined4 **)0x0;
        if (uVar9 == 0x31415352) {
          ppuVar10 = (undefined4 **)(((uint)((int)ppuVar6 + 7) >> 3) + 4);
          goto LAB_00573630;
        }
      }
      else if ((uVar9 == 0x32415352) || (uVar9 == 0x32535344)) {
        pcVar26 = *(code **)(puStack_620 + -0x6eac);
        ppuVar17 = (undefined4 **)&DAT_00000078;
        uStack_628 = 0xc3;
        goto LAB_005735cc;
      }
      pcVar26 = *(code **)(puStack_620 + -0x6eac);
      ppuVar17 = (undefined4 **)&DAT_00000074;
      uStack_628 = 0xc9;
      goto LAB_005735cc;
    }
    param_5 = (undefined4 **)0x1;
    ppuVar10 = (undefined4 **)(((uint)((int)ppuVar6 + 7) >> 3) * 3 + 0x2c);
LAB_00573630:
    ppuStack_618 = &puStack_604;
    puVar24 = (undefined4 *)0x670000;
    if ((undefined4 **)0x19000 < ppuVar10) {
      pcVar26 = *(code **)(puStack_620 + -0x6eac);
      ppuVar17 = (undefined4 **)&DAT_00000080;
      uStack_628 = 0x117;
      goto LAB_005735f8;
    }
    param_2 = (undefined4 **)(**(code **)(puStack_620 + -0x7dd8))(ppuVar10,FUN_0066c47c,0x11a);
    if (param_2 == (undefined4 **)0x0) {
      ppuVar17 = (undefined4 **)&DAT_00000041;
      ppuVar22 = (undefined4 **)0x85;
      uStack_628 = 0x11c;
      (**(code **)(puStack_620 + -0x6eac))(9,0x85,0x41,FUN_0066c47c);
      ppuVar8 = (undefined4 **)0x0;
    }
    else {
      ppuStack_618 = param_2;
      ppuVar22 = (undefined4 **)(**(code **)(puStack_620 + -0x7920))(puStack_654,param_2,ppuVar10);
      if (ppuVar10 == ppuVar22) {
        ppuVar17 = (undefined4 **)0x1;
        ppuVar22 = ppuVar6;
        if (param_5 == (undefined4 **)0x0) {
          ppuVar8 = (undefined4 **)b2i_rsa_isra_1(&ppuStack_618);
        }
        else {
          ppuVar8 = (undefined4 **)b2i_dss_isra_0();
        }
      }
      else {
        ppuVar17 = (undefined4 **)0x7b;
        ppuVar22 = (undefined4 **)0x85;
        uStack_628 = 0x121;
        ppuVar8 = (undefined4 **)0x0;
        (**(code **)(puStack_620 + -0x6eac))(9,0x85,0x7b,FUN_0066c47c);
      }
      (**(code **)(puStack_620 + -0x7f58))(param_2);
      ppuVar10 = ppuVar8;
    }
  }
  else {
    pcVar26 = *(code **)(puStack_620 + -0x6eac);
    ppuVar17 = (undefined4 **)0x7b;
    uStack_628 = 0x10e;
LAB_005735f8:
    ppuVar22 = (undefined4 **)0x85;
    (*pcVar26)(9,0x85,ppuVar17,FUN_0066c47c);
LAB_00573528:
    ppuVar8 = (undefined4 **)0x0;
  }
  if (puStack_604 == *ppuVar7) {
    return ppuVar8;
  }
  pcStack_63c = i2b_PrivateKey_bio;
  puVar3 = puStack_604;
  (**(code **)(puStack_620 + -0x5330))();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puStack_65c = (undefined *)ppuVar7;
  puStack_668 = (undefined4 *)0x0;
  iStack_664 = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppuStack_660 = ppuVar10;
  ppuStack_658 = ppuVar6;
  ppuStack_650 = param_5;
  ppuStack_64c = param_2;
  puStack_648 = puVar24;
  ppuStack_644 = unaff_s7;
  puStack_640 = unaff_s8;
  if (*ppuVar22 == (undefined4 *)0x74) {
    ppuVar10 = (undefined4 **)ppuVar22[5];
    ppuVar6 = (undefined4 **)(*(code *)PTR_BN_num_bits_006a71f4)(ppuVar10[3]);
    if ((((((uint)ppuVar6 & 7) != 0) ||
         (iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(ppuVar10[4]), iVar4 != 0xa0)) ||
        (iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(ppuVar10[5]), (int)ppuVar6 < iVar4)) ||
       (iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(ppuVar10[7]), 0xa0 < iVar4)) {
      ppuVar17 = (undefined4 **)0x7e;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x82,0x7e,FUN_0066c47c,0x222);
      goto LAB_00573fe8;
    }
    puStack_668 = (undefined4 *)0x32535344;
    if (ppuVar6 == (undefined4 **)0x0) goto LAB_00573fe8;
    unaff_s7 = (undefined4 **)0x22;
    puVar24 = (undefined4 *)0x2200;
    iVar4 = (((uint)((int)ppuVar6 + 7) >> 3) + 0x20) * 2;
  }
  else {
    ppuVar8 = (undefined4 **)0xffffffff;
    if (*ppuVar22 != (undefined4 *)0x6) goto LAB_00573f4c;
    ppuVar17 = &puStack_668;
    ppuVar6 = (undefined4 **)check_bitlen_rsa(ppuVar22[5],0);
    if (ppuVar6 == (undefined4 **)0x0) goto LAB_00573fe8;
    unaff_s7 = (undefined4 **)&DAT_000000a4;
    iVar4 = (((uint)((int)ppuVar6 + 7) >> 3) + 2) * 2 + ((uint)((int)ppuVar6 + 0xf) >> 4) * 5;
    puVar24 = (undefined4 *)0xa400;
  }
  ppuVar8 = (undefined4 **)(iVar4 + 0x10);
  ppuVar17 = (undefined4 **)0x1e8;
  ppuVar10 = (undefined4 **)(*(code *)PTR_CRYPTO_malloc_006a7008)(ppuVar8,FUN_0066c47c);
  ppuVar7 = ppuVar8;
  if (ppuVar10 == (undefined4 **)0x0) goto LAB_00573fe8;
  *(char *)((int)ppuVar10 + 2) = '\0';
  *(char *)((int)ppuVar10 + 3) = '\0';
  *(char *)(ppuVar10 + 1) = '\0';
  *(char *)((int)ppuVar10 + 5) = (char)unaff_s7;
  *(char *)((int)ppuVar10 + 6) = '\0';
  *(char *)ppuVar10 = '\a';
  ppuVar7 = ppuVar10 + 4;
  *(char *)((int)ppuVar10 + 7) = '\0';
  *(char *)(ppuVar10 + 3) = (char)ppuVar6;
  *(char *)((int)ppuVar10 + 1) = '\x02';
  *(char *)((int)ppuVar10 + 0xd) = (char)((uint)ppuVar6 >> 8);
  *(char *)((int)ppuVar10 + 0xe) = (char)((uint)ppuVar6 >> 0x10);
  *(char *)((int)ppuVar10 + 0xf) = (char)((uint)ppuVar6 >> 0x18);
  *(char *)(ppuVar10 + 2) = (char)puStack_668;
  *(char *)((int)ppuVar10 + 9) = (char)((uint)puStack_668 >> 8);
  *(char *)((int)ppuVar10 + 10) = (char)((uint)puStack_668 >> 0x10);
  *(char *)((int)ppuVar10 + 0xb) = (char)((uint)puStack_668 >> 0x18);
  if (puVar24 == (undefined4 *)0x2200) {
    puVar24 = ppuVar22[5];
    iVar11 = (*(code *)PTR_BN_num_bits_006a71f4)(puVar24[3]);
    uVar19 = puVar24[3];
    iVar4 = iVar11 + 7;
    if (iVar11 + 7 < 0) {
      iVar4 = iVar11 + 0xe;
    }
    iVar4 = iVar4 >> 3;
    iVar20 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar19);
    iVar21 = iVar20 + 7;
    iVar11 = iVar20 + 0xe;
    if (-1 < iVar21) {
      iVar11 = iVar21;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar19,ppuVar7);
    iVar11 = iVar11 >> 3;
    iVar20 = iVar20 + 0x16;
    if (-1 < iVar21) {
      iVar20 = iVar21;
    }
    if (0 < iVar20 >> 4) {
      ppuVar6 = ppuVar7;
      pcVar5 = (char *)((int)ppuVar7 + iVar11 + -1);
      do {
        cVar1 = *(char *)ppuVar6;
        ppuVar22 = (undefined4 **)((int)ppuVar6 + 1);
        *(char *)ppuVar6 = *pcVar5;
        *pcVar5 = cVar1;
        ppuVar6 = ppuVar22;
        pcVar5 = pcVar5 + -1;
      } while ((undefined4 **)((int)ppuVar7 + (iVar20 >> 4)) != ppuVar22);
    }
    pcVar25 = (char *)((int)ppuVar7 + iVar11);
    pcVar5 = pcVar25;
    if ((0 < iVar4) && (0 < iVar4 - iVar11)) {
      pcVar5 = pcVar25 + (iVar4 - iVar11);
      (*(code *)PTR_memset_006a99f4)(pcVar25,0);
    }
    uVar19 = puVar24[4];
    iVar20 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar19);
    iVar21 = iVar20 + 7;
    iVar11 = iVar20 + 0xe;
    if (-1 < iVar21) {
      iVar11 = iVar21;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar19,pcVar5);
    iVar11 = iVar11 >> 3;
    iVar20 = iVar20 + 0x16;
    if (-1 < iVar21) {
      iVar20 = iVar21;
    }
    if (0 < iVar20 >> 4) {
      pcVar25 = pcVar5;
      pcVar14 = pcVar5 + iVar11 + -1;
      do {
        cVar1 = *pcVar25;
        pcVar13 = pcVar25 + 1;
        *pcVar25 = *pcVar14;
        *pcVar14 = cVar1;
        pcVar25 = pcVar13;
        pcVar14 = pcVar14 + -1;
      } while (pcVar5 + (iVar20 >> 4) != pcVar13);
    }
    pcVar5 = pcVar5 + iVar11;
    pcVar25 = pcVar5;
    if (0 < 0x14 - iVar11) {
      pcVar25 = pcVar5 + (0x14 - iVar11);
      (*(code *)PTR_memset_006a99f4)(pcVar5,0);
    }
    uVar19 = puVar24[5];
    iVar21 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar19);
    iVar20 = iVar21 + 7;
    iVar11 = iVar21 + 0xe;
    if (-1 < iVar20) {
      iVar11 = iVar20;
    }
    iVar11 = iVar11 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar19,pcVar25);
    if (-1 >= iVar20) {
      iVar20 = iVar21 + 0x16;
    }
    if (0 < iVar20 >> 4) {
      pcVar5 = pcVar25;
      pcVar14 = pcVar25 + iVar11 + -1;
      do {
        cVar1 = *pcVar5;
        pcVar13 = pcVar5 + 1;
        *pcVar5 = *pcVar14;
        *pcVar14 = cVar1;
        pcVar5 = pcVar13;
        pcVar14 = pcVar14 + -1;
      } while (pcVar13 != pcVar25 + (iVar20 >> 4));
    }
    ppuVar6 = (undefined4 **)(pcVar25 + iVar11);
    unaff_s7 = ppuVar6;
    if ((0 < iVar4) && (0 < iVar4 - iVar11)) {
      unaff_s7 = (undefined4 **)((int)ppuVar6 + (iVar4 - iVar11));
      (*(code *)PTR_memset_006a99f4)(ppuVar6,0);
    }
    uVar19 = puVar24[7];
    iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar19);
    puVar27 = (undefined4 *)(iVar4 + 7);
    puVar23 = (undefined4 *)(iVar4 + 0xe);
    if (-1 < (int)puVar27) {
      puVar23 = puVar27;
    }
    puVar24 = (undefined4 *)(iVar4 + 0x16);
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar19,unaff_s7);
    if (-1 >= (int)puVar27) {
      puVar27 = puVar24;
    }
    ppuVar22 = (undefined4 **)((int)puVar23 >> 3);
    if (0 < (int)puVar27 >> 4) {
      ppuVar6 = unaff_s7;
      pcVar5 = (char *)((int)unaff_s7 + (int)((int)ppuVar22 + -1));
      do {
        cVar1 = *(char *)ppuVar6;
        ppuVar7 = (undefined4 **)((int)ppuVar6 + 1);
        *(char *)ppuVar6 = *pcVar5;
        *pcVar5 = cVar1;
        ppuVar6 = ppuVar7;
        pcVar5 = pcVar5 + -1;
      } while (ppuVar7 != (undefined4 **)((int)unaff_s7 + ((int)puVar27 >> 4)));
    }
    ppuVar7 = (undefined4 **)((int)unaff_s7 + (int)ppuVar22);
    ppuVar6 = ppuVar7;
    if (0 < 0x14 - (int)ppuVar22) {
      ppuVar6 = (undefined4 **)((int)ppuVar7 + (0x14 - (int)ppuVar22));
      (*(code *)PTR_memset_006a99f4)(ppuVar7,0);
    }
    ppuVar17 = (undefined4 **)&DAT_00000018;
    (*(code *)PTR_memset_006a99f4)(ppuVar6,0xff);
    ppuVar12 = ppuVar10;
    goto LAB_00573f14;
  }
  puVar24 = ppuVar22[5];
  iVar11 = (*(code *)PTR_BN_num_bits_006a71f4)(puVar24[4]);
  iVar4 = iVar11 + 7;
  if (iVar11 + 7 < 0) {
    iVar4 = iVar11 + 0xe;
  }
  ppuVar22 = (undefined4 **)(iVar4 >> 3);
  iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(puVar24[4]);
  uVar19 = puVar24[5];
  ppuVar6 = (undefined4 **)(iVar4 + 0xf >> 4);
  iVar11 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar19);
  iVar20 = iVar11 + 7;
  iVar4 = iVar11 + 0xe;
  if (-1 < iVar20) {
    iVar4 = iVar20;
  }
  iVar4 = iVar4 >> 3;
  (*(code *)PTR_BN_bn2bin_006a7200)(uVar19,ppuVar7);
  iVar11 = iVar11 + 0x16;
  if (-1 < iVar20) {
    iVar11 = iVar20;
  }
  if (0 < iVar11 >> 4) {
    ppuVar17 = ppuVar7;
    pcVar5 = (char *)((int)ppuVar7 + iVar4 + -1);
    do {
      cVar1 = *(char *)ppuVar17;
      ppuVar12 = (undefined4 **)((int)ppuVar17 + 1);
      *(char *)ppuVar17 = *pcVar5;
      *pcVar5 = cVar1;
      ppuVar17 = ppuVar12;
      pcVar5 = pcVar5 + -1;
    } while ((undefined4 **)((int)ppuVar7 + (iVar11 >> 4)) != ppuVar12);
  }
  pcVar25 = (char *)((int)ppuVar7 + iVar4);
  pcVar5 = pcVar25;
  if (0 < 4 - iVar4) {
    pcVar5 = pcVar25 + (4 - iVar4);
    (*(code *)PTR_memset_006a99f4)(pcVar25,0);
  }
  uVar19 = puVar24[4];
  iVar20 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar19);
  iVar11 = iVar20 + 7;
  (*(code *)PTR_BN_bn2bin_006a7200)(uVar19,pcVar5);
  iVar4 = iVar11;
  if (iVar11 < 0) {
    iVar11 = iVar20 + 0x16;
    iVar4 = iVar20 + 0xe;
  }
  if (0 < iVar11 >> 4) {
    pcVar25 = pcVar5;
    pcVar14 = pcVar5 + (iVar4 >> 3) + -1;
    do {
      cVar1 = *pcVar25;
      pcVar13 = pcVar25 + 1;
      *pcVar25 = *pcVar14;
      *pcVar14 = cVar1;
      pcVar25 = pcVar13;
      pcVar14 = pcVar14 + -1;
    } while (pcVar13 != pcVar5 + (iVar11 >> 4));
  }
  uVar19 = puVar24[7];
  pcVar5 = pcVar5 + (iVar4 >> 3);
  iVar11 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar19);
  iVar20 = iVar11 + 7;
  iVar4 = iVar11 + 0xe;
  if (-1 < iVar20) {
    iVar4 = iVar20;
  }
  iVar4 = iVar4 >> 3;
  (*(code *)PTR_BN_bn2bin_006a7200)(uVar19,pcVar5);
  iVar11 = iVar11 + 0x16;
  if (-1 < iVar20) {
    iVar11 = iVar20;
  }
  if (0 < iVar11 >> 4) {
    pcVar25 = pcVar5;
    pcVar14 = pcVar5 + iVar4 + -1;
    do {
      cVar1 = *pcVar25;
      pcVar13 = pcVar25 + 1;
      *pcVar25 = *pcVar14;
      *pcVar14 = cVar1;
      pcVar25 = pcVar13;
      pcVar14 = pcVar14 + -1;
    } while (pcVar5 + (iVar11 >> 4) != pcVar13);
  }
  pcVar5 = pcVar5 + iVar4;
  if ((int)ppuVar6 < 1) {
    uVar19 = puVar24[8];
    iVar11 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar19);
    iVar20 = iVar11 + 7;
    iVar4 = iVar11 + 0xe;
    if (-1 < iVar20) {
      iVar4 = iVar20;
    }
    iVar4 = iVar4 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar19,pcVar5);
    iVar11 = iVar11 + 0x16;
    if (-1 < iVar20) {
      iVar11 = iVar20;
    }
    iVar11 = iVar11 >> 4;
    pcVar25 = pcVar5 + iVar4 + -1;
    if (0 < iVar11) goto LAB_00573bc8;
    pcVar5 = pcVar5 + iVar4;
LAB_00574388:
    uVar19 = puVar24[9];
    iVar11 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar19);
    iVar20 = iVar11 + 7;
    iVar4 = iVar11 + 0xe;
    if (-1 < iVar20) {
      iVar4 = iVar20;
    }
    iVar4 = iVar4 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar19,pcVar5);
    iVar11 = iVar11 + 0x16;
    if (-1 < iVar20) {
      iVar11 = iVar20;
    }
    iVar11 = iVar11 >> 4;
    pcVar25 = pcVar5 + iVar4 + -1;
    if (0 < iVar11) goto LAB_00573c8c;
    pcVar5 = pcVar5 + iVar4;
LAB_00574400:
    uVar19 = puVar24[10];
    iVar20 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar19);
    iVar4 = iVar20 + 7;
    iVar11 = iVar20 + 0xe;
    if (-1 < iVar4) {
      iVar11 = iVar4;
    }
    iVar11 = iVar11 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar19,pcVar5);
    if (-1 >= iVar4) {
      iVar4 = iVar20 + 0x16;
    }
    iVar4 = iVar4 >> 4;
    pcVar25 = pcVar5 + iVar11 + -1;
    if (0 < iVar4) goto LAB_00573d50;
LAB_00573d74:
    unaff_s7 = (undefined4 **)(pcVar5 + iVar11);
    if ((int)ppuVar6 < 1) {
      uVar19 = puVar24[0xb];
      iVar20 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar19);
      iVar11 = iVar20 + 7;
      iVar4 = iVar20 + 0xe;
      if (-1 < iVar11) {
        iVar4 = iVar11;
      }
      ppuVar17 = (undefined4 **)(iVar4 >> 3);
      (*(code *)PTR_BN_bn2bin_006a7200)(uVar19,unaff_s7);
      if (-1 >= iVar11) {
        iVar11 = iVar20 + 0x16;
      }
      iVar11 = iVar11 >> 4;
      pcVar5 = (char *)((int)unaff_s7 + (int)((int)ppuVar17 + -1));
      if (iVar11 < 1) {
        unaff_s7 = (undefined4 **)((int)unaff_s7 + (int)ppuVar17);
        goto LAB_00573e60;
      }
      goto LAB_00573e14;
    }
  }
  else {
    iVar4 = (int)ppuVar6 - iVar4;
    if (0 < iVar4) {
      (*(code *)PTR_memset_006a99f4)(pcVar5,0,iVar4);
      pcVar5 = pcVar5 + iVar4;
    }
    uVar19 = puVar24[8];
    iVar11 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar19);
    iVar20 = iVar11 + 7;
    iVar4 = iVar11 + 0xe;
    if (-1 < iVar20) {
      iVar4 = iVar20;
    }
    iVar4 = iVar4 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar19,pcVar5);
    iVar11 = iVar11 + 0x16;
    if (-1 < iVar20) {
      iVar11 = iVar20;
    }
    iVar11 = iVar11 >> 4;
    pcVar25 = pcVar5 + iVar4 + -1;
    if (iVar11 < 1) {
      pcVar5 = pcVar5 + iVar4;
    }
    else {
LAB_00573bc8:
      pcVar14 = pcVar5;
      do {
        cVar1 = *pcVar14;
        pcVar13 = pcVar14 + 1;
        *pcVar14 = *pcVar25;
        *pcVar25 = cVar1;
        pcVar14 = pcVar13;
        pcVar25 = pcVar25 + -1;
      } while (pcVar5 + iVar11 != pcVar13);
      pcVar5 = pcVar5 + iVar4;
      if ((int)ppuVar6 < 1) goto LAB_00574388;
    }
    iVar4 = (int)ppuVar6 - iVar4;
    if (0 < iVar4) {
      (*(code *)PTR_memset_006a99f4)(pcVar5,0,iVar4);
      pcVar5 = pcVar5 + iVar4;
    }
    uVar19 = puVar24[9];
    iVar11 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar19);
    iVar20 = iVar11 + 7;
    iVar4 = iVar11 + 0xe;
    if (-1 < iVar20) {
      iVar4 = iVar20;
    }
    iVar4 = iVar4 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar19,pcVar5);
    iVar11 = iVar11 + 0x16;
    if (-1 < iVar20) {
      iVar11 = iVar20;
    }
    iVar11 = iVar11 >> 4;
    pcVar25 = pcVar5 + iVar4 + -1;
    if (iVar11 < 1) {
      pcVar5 = pcVar5 + iVar4;
    }
    else {
LAB_00573c8c:
      pcVar14 = pcVar5;
      do {
        cVar1 = *pcVar14;
        pcVar13 = pcVar14 + 1;
        *pcVar14 = *pcVar25;
        *pcVar25 = cVar1;
        pcVar14 = pcVar13;
        pcVar25 = pcVar25 + -1;
      } while (pcVar5 + iVar11 != pcVar13);
      pcVar5 = pcVar5 + iVar4;
      if ((int)ppuVar6 < 1) goto LAB_00574400;
    }
    iVar4 = (int)ppuVar6 - iVar4;
    if (0 < iVar4) {
      (*(code *)PTR_memset_006a99f4)(pcVar5,0,iVar4);
      pcVar5 = pcVar5 + iVar4;
    }
    uVar19 = puVar24[10];
    iVar20 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar19);
    iVar4 = iVar20 + 7;
    iVar11 = iVar20 + 0xe;
    if (-1 < iVar4) {
      iVar11 = iVar4;
    }
    iVar11 = iVar11 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar19,pcVar5);
    if (-1 >= iVar4) {
      iVar4 = iVar20 + 0x16;
    }
    iVar4 = iVar4 >> 4;
    pcVar25 = pcVar5 + iVar11 + -1;
    if (0 < iVar4) {
LAB_00573d50:
      pcVar14 = pcVar5;
      do {
        cVar1 = *pcVar14;
        pcVar13 = pcVar14 + 1;
        *pcVar14 = *pcVar25;
        *pcVar25 = cVar1;
        pcVar25 = pcVar25 + -1;
        pcVar14 = pcVar13;
      } while (pcVar5 + iVar4 != pcVar13);
      goto LAB_00573d74;
    }
    unaff_s7 = (undefined4 **)(pcVar5 + iVar11);
  }
  iVar11 = (int)ppuVar6 - iVar11;
  if (0 < iVar11) {
    (*(code *)PTR_memset_006a99f4)(unaff_s7,0,iVar11);
    unaff_s7 = (undefined4 **)((int)unaff_s7 + iVar11);
  }
  uVar19 = puVar24[0xb];
  iVar20 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar19);
  iVar11 = iVar20 + 7;
  iVar4 = iVar20 + 0xe;
  if (-1 < iVar11) {
    iVar4 = iVar11;
  }
  ppuVar17 = (undefined4 **)(iVar4 >> 3);
  (*(code *)PTR_BN_bn2bin_006a7200)(uVar19,unaff_s7);
  if (-1 >= iVar11) {
    iVar11 = iVar20 + 0x16;
  }
  iVar11 = iVar11 >> 4;
  pcVar5 = (char *)((int)unaff_s7 + (int)((int)ppuVar17 + -1));
  if (iVar11 < 1) goto LAB_00574578;
LAB_00573e14:
  ppuVar7 = unaff_s7;
  do {
    cVar1 = *(char *)ppuVar7;
    ppuVar12 = (undefined4 **)((int)ppuVar7 + 1);
    *(char *)ppuVar7 = *pcVar5;
    *pcVar5 = cVar1;
    pcVar5 = pcVar5 + -1;
    ppuVar7 = ppuVar12;
  } while ((undefined4 **)((int)unaff_s7 + iVar11) != ppuVar12);
  ppuVar7 = (undefined4 **)((int)unaff_s7 + (int)ppuVar17);
  unaff_s7 = ppuVar7;
  if ((int)ppuVar6 < 1) goto LAB_00573e60;
  do {
    unaff_s7 = ppuVar7;
    if (0 < (int)ppuVar6 - (int)ppuVar17) {
      unaff_s7 = (undefined4 **)((int)ppuVar7 + ((int)ppuVar6 - (int)ppuVar17));
      (*(code *)PTR_memset_006a99f4)(ppuVar7,0);
    }
LAB_00573e60:
    uVar19 = puVar24[6];
    iVar20 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar19);
    iVar4 = iVar20 + 7;
    ppuVar6 = (undefined4 **)(uint)(iVar4 < 0);
    iVar11 = iVar20 + 0xe;
    if (ppuVar6 == (undefined4 **)0x0) {
      iVar11 = iVar4;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar19,unaff_s7);
    puVar24 = (undefined4 *)(iVar11 >> 3);
    if (ppuVar6 != (undefined4 **)0x0) {
      iVar4 = iVar20 + 0x16;
    }
    ppuVar17 = (undefined4 **)(iVar4 >> 4);
    if (0 < (int)ppuVar17) {
      ppuVar17 = (undefined4 **)((int)unaff_s7 + (int)ppuVar17);
      pcVar5 = (char *)((int)unaff_s7 + (int)((int)puVar24 + -1));
      ppuVar7 = unaff_s7;
      do {
        cVar1 = *(char *)ppuVar7;
        ppuVar12 = (undefined4 **)((int)ppuVar7 + 1);
        *(char *)ppuVar7 = *pcVar5;
        *pcVar5 = cVar1;
        pcVar5 = pcVar5 + -1;
        ppuVar7 = ppuVar12;
      } while (ppuVar17 != ppuVar12);
    }
    ppuVar12 = ppuVar10;
    if ((0 < (int)ppuVar22) &&
       (ppuVar17 = (undefined4 **)((int)ppuVar22 - (int)puVar24), 0 < (int)ppuVar17)) {
      (*(code *)PTR_memset_006a99f4)((char *)((int)unaff_s7 + (int)puVar24),0);
    }
LAB_00573f14:
    ppuVar10 = ppuVar12;
    ppuVar7 = ppuVar8;
    if ((int)ppuVar8 < 0) {
LAB_00573fe8:
      ppuVar8 = (undefined4 **)0xffffffff;
    }
    else {
      ppuVar17 = ppuVar8;
      ppuVar10 = (undefined4 **)(*(code *)PTR_BIO_write_006a6e14)(puVar3,ppuVar12);
      (*(code *)PTR_CRYPTO_free_006a6e88)(ppuVar12);
      if (ppuVar10 != ppuVar8) goto LAB_00573fe8;
    }
LAB_00573f4c:
    if (iStack_664 == *(int *)puVar2) {
      return ppuVar8;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    ppuVar8 = ppuVar7;
LAB_00574578:
    ppuVar7 = (undefined4 **)((int)unaff_s7 + (int)ppuVar17);
  } while( true );
}

