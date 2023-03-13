
undefined4 ** b2i_rsa_isra_1(byte **param_1,uint param_2,byte *param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  char cVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 ****ppppuVar8;
  undefined4 ****ppppuVar9;
  undefined4 *puVar10;
  char *pcVar11;
  undefined4 **ppuVar12;
  undefined4 **ppuVar13;
  undefined4 **ppuVar14;
  uint uVar15;
  undefined4 **ppuVar16;
  int iVar17;
  undefined4 **ppuVar18;
  char *pcVar19;
  char *pcVar20;
  char **ppcVar21;
  uint uVar22;
  undefined4 **ppuVar23;
  uint uVar24;
  undefined4 uVar25;
  int iVar26;
  int iVar27;
  undefined4 ****unaff_s1;
  undefined4 *puVar28;
  undefined4 **ppuVar29;
  undefined4 *puVar30;
  byte *pbVar31;
  undefined4 **unaff_s7;
  char *pcVar32;
  code *pcVar33;
  undefined4 *unaff_s8;
  undefined4 *puStack_6c0;
  int iStack_6bc;
  undefined4 **ppuStack_6b8;
  undefined *puStack_6b4;
  undefined4 **ppuStack_6b0;
  undefined4 *puStack_6ac;
  undefined4 **ppuStack_6a8;
  undefined4 **ppuStack_6a4;
  undefined4 *puStack_6a0;
  undefined4 **ppuStack_69c;
  undefined4 *puStack_698;
  code *pcStack_694;
  undefined4 uStack_680;
  undefined *puStack_678;
  undefined4 **ppuStack_670;
  char cStack_66c;
  char cStack_66b;
  uint uStack_664;
  uint uStack_660;
  undefined4 *puStack_65c;
  undefined4 **ppuStack_658;
  undefined *puStack_654;
  undefined4 **ppuStack_650;
  undefined *puStack_64c;
  undefined4 **ppuStack_648;
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
  undefined *puStack_600;
  undefined4 **ppuStack_5fc;
  undefined4 **ppuStack_5f8;
  undefined *puStack_5f4;
  undefined4 **ppuStack_5f0;
  undefined4 **ppuStack_5ec;
  undefined *puStack_5e8;
  code *pcStack_5e4;
  undefined4 uStack_5d0;
  undefined *puStack_5c8;
  char *pcStack_5c0;
  undefined4 **ppuStack_5bc;
  undefined *puStack_5b4;
  undefined4 **ppuStack_5b0;
  code *pcStack_5ac;
  undefined4 uStack_598;
  undefined *puStack_590;
  char *pcStack_588;
  char **ppcStack_584;
  code *pcStack_57c;
  undefined4 **ppuStack_578;
  code *pcStack_574;
  undefined4 **ppuStack_560;
  undefined *puStack_558;
  undefined4 *puStack_54c;
  undefined4 **ppuStack_548;
  undefined4 **ppuStack_544;
  undefined4 *apuStack_53c [6];
  undefined auStack_524 [140];
  undefined4 uStack_498;
  undefined uStack_493;
  undefined uStack_492;
  undefined uStack_491;
  undefined uStack_490;
  undefined uStack_48f;
  undefined uStack_48e;
  undefined uStack_48d;
  undefined uStack_48c;
  undefined uStack_48b;
  undefined uStack_48a;
  undefined uStack_489;
  undefined4 auStack_484 [256];
  char **ppcStack_84;
  undefined4 **ppuStack_80;
  undefined4 ****ppppuStack_7c;
  undefined4 **ppuStack_78;
  undefined *puStack_74;
  byte **ppbStack_70;
  uint uStack_6c;
  byte *pbStack_68;
  undefined4 **ppuStack_64;
  undefined4 *puStack_60;
  code *pcStack_5c;
  undefined4 **local_48;
  undefined *local_40;
  undefined4 *local_34;
  undefined4 ****local_30;
  undefined4 *local_2c;
  
  puStack_74 = PTR___stack_chk_guard_006a9ae8;
  local_30 = (undefined4 ****)*param_1;
  local_40 = &_gp;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  ppuStack_78 = (undefined4 **)(*(code *)PTR_RSA_new_006a787c)();
  ppuStack_80 = (undefined4 **)(**(code **)(local_40 + -0x77c0))();
  if (ppuStack_78 == (undefined4 **)0x0) {
    ppuStack_5f8 = (undefined4 **)&DAT_00000041;
    pcStack_57c = FUN_0066c47c;
    local_48 = (undefined4 **)0x18e;
    ppuStack_6a4 = (undefined4 **)0x81;
    (**(code **)(local_40 + -0x6eac))(9);
LAB_00572234:
    if (ppuStack_80 == (undefined4 **)0x0) {
      ppuVar12 = (undefined4 **)0x0;
    }
    else {
      (**(code **)(local_40 + -0x7f68))(ppuStack_80);
      ppuVar12 = (undefined4 **)0x0;
    }
  }
  else {
    if (ppuStack_80 == (undefined4 **)0x0) {
LAB_00572200:
      unaff_s7 = (undefined4 **)0x670000;
      pcStack_57c = FUN_0066c47c;
      ppuStack_5f8 = (undefined4 **)&DAT_00000041;
      ppuStack_6a4 = (undefined4 **)0x81;
      local_48 = (undefined4 **)0x18e;
      (**(code **)(local_40 + -0x6eac))(9);
      (**(code **)(local_40 + -0x77e0))(ppuStack_78);
      goto LAB_00572234;
    }
    puVar6 = (undefined4 *)(**(code **)(local_40 + -0x7c2c))();
    ppuStack_78[5] = puVar6;
    if (puVar6 == (undefined4 *)0x0) goto LAB_00572200;
    pbVar31 = (byte *)((int)local_30 + 1);
    pbVar1 = (byte *)((int)local_30 + 2);
    pbVar2 = (byte *)((int)local_30 + 3);
    bVar3 = *(byte *)local_30;
    local_30 = local_30 + 1;
    iVar7 = (**(code **)(local_40 + -0x76b0))
                      (puVar6,(uint)*pbVar2 << 0x18 |
                              (uint)*pbVar31 << 8 | (uint)*pbVar1 << 0x10 | (uint)bVar3);
    if (iVar7 == 0) goto LAB_00572200;
    unaff_s7 = (undefined4 **)0x670000;
    unaff_s8 = (undefined4 *)(param_2 + 7 >> 3);
    unaff_s1 = (undefined4 ****)((int)local_30 + (int)((int)unaff_s8 + -1));
    puVar6 = (undefined4 *)(**(code **)(local_40 + -0x7dd8))(unaff_s8,FUN_0066c47c,100);
    if (puVar6 == (undefined4 *)0x0) goto LAB_00572200;
    pcVar33 = *(code **)(local_40 + -0x74dc);
    if (unaff_s8 != (undefined4 *)0x0) {
      puVar28 = puVar6;
      ppppuVar8 = unaff_s1;
      do {
        unaff_s1 = (undefined4 ****)((int)ppppuVar8 + -1);
        puVar10 = (undefined4 *)((int)puVar28 + 1);
        *(byte *)puVar28 = *(byte *)ppppuVar8;
        puVar28 = puVar10;
        ppppuVar8 = unaff_s1;
      } while (puVar10 != (undefined4 *)((int)puVar6 + (int)unaff_s8));
      pcVar33 = *(code **)(local_40 + -0x74dc);
    }
    ppuStack_5f8 = (undefined4 **)0x0;
    local_34 = puVar6;
    puVar6 = (undefined4 *)(*pcVar33)(puVar6,unaff_s8);
    ppuStack_78[4] = puVar6;
    pcStack_57c = (code *)local_34;
    (**(code **)(local_40 + -0x7f58))(local_34);
    if (ppuStack_78[4] == (undefined4 *)0x0) goto LAB_00572200;
    unaff_s1 = (undefined4 ****)((int)local_30 + (int)unaff_s8);
    local_30 = unaff_s1;
    if (param_3 == (byte *)0x0) {
      param_2 = param_2 + 0xf >> 4;
      param_3 = (byte *)(param_2 - 1);
      puVar6 = (undefined4 *)(**(code **)(local_40 + -0x7dd8))(param_2,FUN_0066c47c,100);
      unaff_s1 = (undefined4 ****)((int)unaff_s1 + (int)param_3);
      if (puVar6 != (undefined4 *)0x0) {
        pcVar33 = *(code **)(local_40 + -0x74dc);
        if (param_2 != 0) {
          puVar28 = puVar6;
          ppppuVar8 = unaff_s1;
          do {
            unaff_s1 = (undefined4 ****)((int)ppppuVar8 + -1);
            puVar10 = (undefined4 *)((int)puVar28 + 1);
            *(byte *)puVar28 = *(byte *)ppppuVar8;
            puVar28 = puVar10;
            ppppuVar8 = unaff_s1;
          } while (puVar10 != (undefined4 *)((int)puVar6 + param_2));
          pcVar33 = *(code **)(local_40 + -0x74dc);
        }
        local_34 = puVar6;
        puVar6 = (undefined4 *)(*pcVar33)(puVar6,param_2,0);
        ppuStack_78[7] = puVar6;
        (**(code **)(local_40 + -0x7f58))(local_34);
        if (ppuStack_78[7] != (undefined4 *)0x0) {
          local_30 = (undefined4 ****)((int)local_30 + param_2);
          unaff_s1 = (undefined4 ****)((int)local_30 + (int)param_3);
          puVar6 = (undefined4 *)(**(code **)(local_40 + -0x7dd8))(param_2,FUN_0066c47c,100);
          if (puVar6 != (undefined4 *)0x0) {
            pcVar33 = *(code **)(local_40 + -0x74dc);
            if (param_2 != 0) {
              puVar28 = puVar6;
              ppppuVar8 = unaff_s1;
              do {
                unaff_s1 = (undefined4 ****)((int)ppppuVar8 + -1);
                puVar10 = (undefined4 *)((int)puVar28 + 1);
                *(byte *)puVar28 = *(byte *)ppppuVar8;
                puVar28 = puVar10;
                ppppuVar8 = unaff_s1;
              } while (puVar10 != (undefined4 *)((int)puVar6 + param_2));
              pcVar33 = *(code **)(local_40 + -0x74dc);
            }
            local_34 = puVar6;
            puVar6 = (undefined4 *)(*pcVar33)(puVar6,param_2,0);
            ppuStack_78[8] = puVar6;
            pcStack_57c = (code *)local_34;
            (**(code **)(local_40 + -0x7f58))(local_34);
            if (ppuStack_78[8] != (undefined4 *)0x0) {
              local_30 = (undefined4 ****)((int)local_30 + param_2);
              param_3 = (byte *)((int)local_30 + (int)param_3);
              unaff_s1 = (undefined4 ****)
                         (**(code **)(local_40 + -0x7dd8))(param_2,FUN_0066c47c,100);
              if (unaff_s1 != (undefined4 ****)0x0) {
                ppppuVar8 = unaff_s1;
                pbVar31 = param_3;
                if (param_2 != 0) {
                  do {
                    param_3 = pbVar31 + -1;
                    ppppuVar9 = (undefined4 ****)((int)ppppuVar8 + 1);
                    *(byte *)ppppuVar8 = *pbVar31;
                    ppppuVar8 = ppppuVar9;
                    pbVar31 = param_3;
                  } while ((undefined4 ****)((int)unaff_s1 + param_2) != ppppuVar9);
                }
                puVar6 = (undefined4 *)(**(code **)(local_40 + -0x74dc))(unaff_s1,param_2,0);
                pcVar33 = *(code **)(local_40 + -0x7f58);
                ppuStack_78[9] = puVar6;
                (*pcVar33)(unaff_s1);
                if (ppuStack_78[9] != (undefined4 *)0x0) {
                  unaff_s1 = &local_30;
                  local_30 = (undefined4 ****)((int)local_30 + param_2);
                  iVar7 = read_lebn(unaff_s1,param_2,ppuStack_78 + 10);
                  if ((iVar7 != 0) &&
                     (iVar7 = read_lebn(unaff_s1,param_2,ppuStack_78 + 0xb), iVar7 != 0)) {
                    ppuStack_5f8 = ppuStack_78 + 6;
                    iVar7 = read_lebn(unaff_s1,unaff_s8);
                    if (iVar7 != 0) goto LAB_00572524;
                  }
                }
              }
            }
          }
        }
      }
      goto LAB_00572200;
    }
LAB_00572524:
    ppuStack_6a4 = ppuStack_78;
    (**(code **)(local_40 + -0x77bc))(ppuStack_80);
    (**(code **)(local_40 + -0x77e0))(ppuStack_78);
    *param_1 = (byte *)local_30;
    ppuVar12 = ppuStack_80;
  }
  if (local_2c == *(undefined4 **)puStack_74) {
    return ppuVar12;
  }
  pcStack_5c = do_PVK_body_isra_3;
  puVar28 = local_2c;
  (**(code **)(local_40 + -0x5330))();
  ppuStack_6a8 = local_48;
  puVar6 = (undefined4 *)PTR___stack_chk_guard_006a9ae8;
  puStack_64c = auStack_524;
  puStack_558 = &_gp;
  ppcStack_84 = *(char ***)PTR___stack_chk_guard_006a9ae8;
  ppppuStack_7c = unaff_s1;
  ppbStack_70 = param_1;
  uStack_6c = param_2;
  pbStack_68 = param_3;
  ppuStack_64 = unaff_s7;
  puStack_60 = unaff_s8;
  (*(code *)PTR_EVP_CIPHER_CTX_init_006a7a64)(puStack_64c);
  if (ppuStack_6a4 == (undefined4 **)0x0) {
    pcStack_57c = (code *)0x0;
    apuStack_53c[0] = puVar28;
    if (ppuStack_5f8 < &SUB_00000010) {
LAB_0057297c:
      puVar10 = (undefined4 *)&DAT_00000084;
      ppuStack_560 = (undefined4 **)0xf8;
      ppuStack_5fc = (undefined4 **)0x0;
      (**(code **)(puStack_558 + -0x6eac))(9,0x84,0x7a,FUN_0066c47c);
    }
    else {
LAB_005729d8:
      if (*(char *)puVar28 == '\x06') {
        pcVar33 = *(code **)(puStack_558 + -0x6eac);
        uVar25 = 0x77;
        ppuStack_560 = (undefined4 **)0x9d;
LAB_00572af4:
        apuStack_53c[0] = puVar28;
        (*pcVar33)(9,0x86,uVar25,FUN_0066c47c);
        goto LAB_0057297c;
      }
      apuStack_53c[0] = puVar28;
      if (*(char *)puVar28 != '\a') goto LAB_0057297c;
      if (*(char *)((int)puVar28 + 1) != '\x02') {
        pcVar33 = *(code **)(puStack_558 + -0x6eac);
        uVar25 = 0x75;
        ppuStack_560 = (undefined4 **)0xac;
        goto LAB_00572af4;
      }
      apuStack_53c[0] = puVar28 + 4;
      uVar15 = (uint)*(byte *)((int)puVar28 + 9) << 8 | (uint)*(byte *)((int)puVar28 + 10) << 0x10 |
               (uint)*(byte *)(puVar28 + 2) | (uint)*(byte *)((int)puVar28 + 0xb) << 0x18;
      puVar10 = (undefined4 *)
                ((uint)*(byte *)((int)puVar28 + 0xd) << 8 |
                 (uint)*(byte *)((int)puVar28 + 0xe) << 0x10 | (uint)*(byte *)(puVar28 + 3) |
                (uint)*(byte *)((int)puVar28 + 0xf) << 0x18);
      if (uVar15 == 0x31535344) {
LAB_00572b20:
        pcVar33 = *(code **)(puStack_558 + -0x6eac);
        uVar25 = 0x77;
        ppuStack_560 = (undefined4 **)0xba;
        goto LAB_00572af4;
      }
      if (uVar15 < 0x31535345) {
        if (uVar15 != 0x31415352) {
          pcVar33 = *(code **)(puStack_558 + -0x6eac);
LAB_00572c78:
          uVar25 = 0x74;
          ppuStack_560 = (undefined4 **)0xc9;
          goto LAB_00572af4;
        }
        goto LAB_00572b20;
      }
      if (uVar15 == 0x32415352) {
        ppuStack_5f8 = ppuStack_5f8 + -4;
        if (ppuStack_5f8 <
            (undefined4 **)
            ((((uint)((int)puVar10 + 7) >> 3) + 2) * 2 + ((uint)((int)puVar10 + 0xf) >> 4) * 5)) {
LAB_00572c28:
          ppuStack_560 = (undefined4 **)0xfd;
          puVar10 = (undefined4 *)&DAT_00000084;
          ppuStack_5fc = (undefined4 **)0x0;
          (**(code **)(puStack_558 + -0x6eac))(9,0x84,0x7b,FUN_0066c47c);
        }
        else {
          ppuStack_5fc = (undefined4 **)b2i_rsa_isra_1(apuStack_53c,puVar10,0);
        }
      }
      else {
        pcVar33 = *(code **)(puStack_558 + -0x6eac);
        if (uVar15 != 0x32535344) goto LAB_00572c78;
        ppuStack_5f8 = (undefined4 **)
                       (uint)(ppuStack_5f8 + -4 <
                             (undefined4 **)((((uint)((int)puVar10 + 7) >> 3) + 0x20) * 2));
        if (ppuStack_5f8 != (undefined4 **)0x0) goto LAB_00572c28;
        ppuStack_5fc = (undefined4 **)b2i_dss_isra_0(apuStack_53c,puVar10,0);
      }
    }
    unaff_s7 = (undefined4 **)0x670000;
    (**(code **)(puStack_558 + -0x736c))(puStack_64c);
    if (((undefined4 *)pcStack_57c != (undefined4 *)0x0) &&
       (pcVar33 = *(code **)(puStack_558 + -0x7f58), ppuStack_6a4 != (undefined4 **)0x0)) {
LAB_005726c0:
      unaff_s7 = (undefined4 **)0x670000;
      (*pcVar33)(pcStack_57c);
    }
  }
  else {
    puStack_54c = auStack_484;
    if ((undefined4 *)pcStack_57c == (undefined4 *)0x0) {
      unaff_s8 = (undefined4 *)PEM_def_callback((char *)puStack_54c,0x400,0,ppuStack_6a8);
    }
    else {
      unaff_s8 = (undefined4 *)(*pcStack_57c)(puStack_54c,0x400,0,ppuStack_6a8);
    }
    if ((int)unaff_s8 < 1) {
      ppuStack_560 = (undefined4 **)0x2c2;
      puVar10 = (undefined4 *)0x87;
      (**(code **)(puStack_558 + -0x6eac))(9,0x87,0x68,FUN_0066c47c);
    }
    else {
      unaff_s7 = (undefined4 **)0x670000;
      pcStack_57c = (code *)(**(code **)(puStack_558 + -0x7dd8))
                                      (ppuStack_5f8 + 2,FUN_0066c47c,0x2c5);
      if ((undefined4 *)pcStack_57c != (undefined4 *)0x0) {
        ppuStack_6a8 = apuStack_53c;
        (**(code **)(puStack_558 + -0x7fc4))(ppuStack_6a8);
        puVar10 = (undefined4 *)(**(code **)(puStack_558 + -0x7810))();
        iVar7 = (**(code **)(puStack_558 + -0x7864))(ppuStack_6a8,puVar10,0);
        if (((iVar7 == 0) ||
            (puVar10 = puVar28,
            iVar7 = (**(code **)(puStack_558 + -0x7860))(ppuStack_6a8,puVar28,ppuStack_6a4),
            iVar7 == 0)) ||
           (puVar10 = puStack_54c,
           iVar7 = (**(code **)(puStack_558 + -0x7860))(ppuStack_6a8,puStack_54c,unaff_s8),
           iVar7 == 0)) {
LAB_00572698:
          (**(code **)(puStack_558 + -0x7fac))(ppuStack_6a8);
        }
        else {
          puVar10 = &uStack_498;
          puStack_54c = puVar10;
          iVar7 = (**(code **)(puStack_558 + -0x785c))(ppuStack_6a8,puVar10,0);
          if (iVar7 == 0) goto LAB_00572698;
          puVar28 = (undefined4 *)((int)puVar28 + (int)ppuStack_6a4);
          (**(code **)(puStack_558 + -0x7fac))(ppuStack_6a8);
          uVar25 = puVar28[1];
          *(undefined4 *)pcStack_57c = *puVar28;
          *(undefined4 *)((int)pcStack_57c + 4) = uVar25;
          if (ppuStack_5f8 < &DAT_00000008) {
            puVar10 = (undefined4 *)0x87;
            ppuStack_560 = (undefined4 **)0x2d2;
            (**(code **)(puStack_558 + -0x6eac))(9,0x87,0x7d,FUN_0066c47c);
          }
          else {
            ppuStack_548 = ppuStack_5f8 + -2;
            unaff_s8 = (undefined4 *)((int)pcStack_57c + 8);
            puVar10 = (undefined4 *)(**(code **)(puStack_558 + -0x69d8))();
            ppuStack_560 = (undefined4 **)0x0;
            iVar7 = (**(code **)(puStack_558 + -0x7378))(puStack_64c,puVar10,0,puStack_54c);
            if (iVar7 != 0) {
              ppuStack_560 = ppuStack_5f8 + -2;
              puVar10 = unaff_s8;
              iVar7 = (**(code **)(puStack_558 + -0x7370))
                                (puStack_64c,unaff_s8,ppuStack_6a8,puVar28 + 2);
              if (iVar7 != 0) {
                puVar10 = (undefined4 *)((int)unaff_s8 + (int)apuStack_53c[0]);
                iVar7 = (**(code **)(puStack_558 + -0x7374))(puStack_64c,puVar10,ppuStack_6a8);
                if (iVar7 != 0) {
                  uVar15 = (uint)*(byte *)((int)pcStack_57c + 9) << 8 |
                           (uint)*(byte *)((int)pcStack_57c + 10) << 0x10 |
                           (uint)*(byte *)((int)pcStack_57c + 8) |
                           (uint)*(byte *)((int)pcStack_57c + 0xb) << 0x18;
                  ppuStack_548 = (undefined4 **)0x32415352;
                  if ((uVar15 == 0x32415352) ||
                     (ppuStack_544 = (undefined4 **)0x32535344, uVar15 == 0x32535344)) {
                    (**(code **)(puStack_558 + -0x7d6c))(puStack_54c,0x14);
LAB_0057296c:
                    puVar28 = (undefined4 *)pcStack_57c;
                    apuStack_53c[0] = (undefined4 *)pcStack_57c;
                    if (&DAT_0000000f < ppuStack_5f8) goto LAB_005729d8;
                    goto LAB_0057297c;
                  }
                  uStack_493 = 0;
                  uStack_492 = 0;
                  uStack_491 = 0;
                  uStack_490 = 0;
                  uStack_48f = 0;
                  uStack_48e = 0;
                  uStack_48d = 0;
                  uStack_48c = 0;
                  uStack_48b = 0;
                  uStack_48a = 0;
                  uStack_489 = 0;
                  puVar10 = (undefined4 *)(**(code **)(puStack_558 + -0x69d8))();
                  ppuStack_560 = (undefined4 **)0x0;
                  iVar7 = (**(code **)(puStack_558 + -0x7378))(puStack_64c,puVar10,0,puStack_54c);
                  if (iVar7 != 0) {
                    (**(code **)(puStack_558 + -0x7d6c))(puStack_54c,0x14);
                    ppuStack_560 = ppuStack_5f8 + -2;
                    puVar10 = unaff_s8;
                    iVar7 = (**(code **)(puStack_558 + -0x7370))
                                      (puStack_64c,unaff_s8,ppuStack_6a8,puVar28 + 2);
                    if (iVar7 != 0) {
                      puVar10 = (undefined4 *)((int)unaff_s8 + (int)apuStack_53c[0]);
                      iVar7 = (**(code **)(puStack_558 + -0x7374))(puStack_64c,puVar10,ppuStack_6a8)
                      ;
                      if (iVar7 != 0) {
                        ppuVar12 = (undefined4 **)
                                   ((uint)*(byte *)((int)pcStack_57c + 9) << 8 |
                                    (uint)*(byte *)((int)pcStack_57c + 10) << 0x10 |
                                    (uint)*(byte *)((int)pcStack_57c + 8) |
                                   (uint)*(byte *)((int)pcStack_57c + 0xb) << 0x18);
                        if ((ppuVar12 == ppuStack_548) || (ppuVar12 == ppuStack_544))
                        goto LAB_0057296c;
                        puVar10 = (undefined4 *)0x87;
                        ppuStack_560 = (undefined4 **)0x2ea;
                        (**(code **)(puStack_558 + -0x6eac))(9,0x87,0x65,FUN_0066c47c);
                      }
                    }
                  }
                }
              }
            }
          }
        }
        ppuStack_5fc = (undefined4 **)0x0;
        (**(code **)(puStack_558 + -0x736c))(puStack_64c);
        pcVar33 = *(code **)(puStack_558 + -0x7f58);
        goto LAB_005726c0;
      }
      puVar10 = (undefined4 *)0x87;
      ppuStack_560 = (undefined4 **)0x2c7;
      (**(code **)(puStack_558 + -0x6eac))(9,0x87,0x41,FUN_0066c47c);
    }
    ppuStack_5fc = (undefined4 **)0x0;
    (**(code **)(puStack_558 + -0x736c))(puStack_64c);
  }
  if (ppcStack_84 == (char **)*puVar6) {
    return ppuStack_5fc;
  }
  pcStack_574 = b2i_PrivateKey;
  ppcVar21 = ppcStack_84;
  (**(code **)(puStack_558 + -0x5330))();
  puStack_5b4 = PTR___stack_chk_guard_006a9ae8;
  pcVar11 = *ppcVar21;
  puStack_590 = &_gp;
  ppcStack_584 = *(char ***)PTR___stack_chk_guard_006a9ae8;
  pcStack_588 = pcVar11;
  ppuStack_578 = ppuStack_5fc;
  if (puVar10 < &SUB_00000010) {
LAB_00572d10:
    ppuStack_5fc = (undefined4 **)0x670000;
    uVar22 = 0x84;
    uStack_598 = 0xf8;
    (**(code **)(puStack_590 + -0x6eac))(9,0x84,0x7a,FUN_0066c47c);
    ppuVar12 = (undefined4 **)0x0;
  }
  else {
    if (*pcVar11 == '\x06') {
      uVar25 = 0x77;
      uStack_598 = 0x9d;
LAB_00572e30:
      pcStack_588 = pcVar11;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x86,uVar25,FUN_0066c47c);
      goto LAB_00572d10;
    }
    if (*pcVar11 != '\a') goto LAB_00572d10;
    if (pcVar11[1] != '\x02') {
      uVar25 = 0x75;
      uStack_598 = 0xac;
      goto LAB_00572e30;
    }
    pcStack_588 = pcVar11 + 0x10;
    uVar15 = (uint)(byte)pcVar11[9] << 8 | (uint)(byte)pcVar11[10] << 0x10 | (uint)(byte)pcVar11[8]
             | (uint)(byte)pcVar11[0xb] << 0x18;
    uVar22 = (uint)(byte)pcVar11[0xd] << 8 | (uint)(byte)pcVar11[0xe] << 0x10 |
             (uint)(byte)pcVar11[0xc] | (uint)(byte)pcVar11[0xf] << 0x18;
    if (uVar15 == 0x31535344) {
LAB_00572ea4:
      uVar25 = 0x77;
      uStack_598 = 0xba;
      goto LAB_00572e30;
    }
    if (uVar15 < 0x31535345) {
      if (uVar15 != 0x31415352) {
LAB_00572ed4:
        uVar25 = 0x74;
        uStack_598 = 0xc9;
        goto LAB_00572e30;
      }
      goto LAB_00572ea4;
    }
    if (uVar15 == 0x32415352) {
      if (puVar10 + -4 < (undefined4 *)(((uVar22 + 7 >> 3) + 2) * 2 + (uVar22 + 0xf >> 4) * 5)) {
LAB_00572eec:
        uStack_598 = 0xfd;
        uVar22 = 0x84;
        (*(code *)PTR_ERR_put_error_006a7f34)(9,0x84,0x7b,FUN_0066c47c);
        ppuVar12 = (undefined4 **)0x0;
      }
      else {
        ppuVar12 = (undefined4 **)b2i_rsa_isra_1(&pcStack_588,uVar22,0);
      }
    }
    else {
      if (uVar15 != 0x32535344) goto LAB_00572ed4;
      if (puVar10 + -4 < (undefined4 *)(((uVar22 + 7 >> 3) + 0x20) * 2)) goto LAB_00572eec;
      ppuVar12 = (undefined4 **)b2i_dss_isra_0(&pcStack_588,uVar22,0);
    }
  }
  if (ppcStack_584 == *(char ***)puStack_5b4) {
    return ppuVar12;
  }
  pcStack_5ac = b2i_PublicKey;
  ppcVar21 = ppcStack_584;
  (**(code **)(puStack_590 + -0x5330))();
  puStack_600 = PTR___stack_chk_guard_006a9ae8;
  pcVar11 = *ppcVar21;
  puStack_5c8 = &_gp;
  ppuStack_5bc = *(undefined4 ***)PTR___stack_chk_guard_006a9ae8;
  pcStack_5c0 = pcVar11;
  ppuStack_5b0 = ppuStack_5fc;
  if (uVar22 < 0x10) {
LAB_00572f80:
    ppuStack_5fc = (undefined4 **)0x670000;
    uStack_5d0 = 0xf8;
    (**(code **)(puStack_5c8 + -0x6eac))(9,0x84,0x7a,FUN_0066c47c);
    ppuVar12 = (undefined4 **)0x0;
  }
  else {
    if (*pcVar11 != '\x06') {
      if (*pcVar11 == '\a') {
        uVar25 = 0x78;
        uStack_5d0 = 0xa3;
        goto LAB_00573088;
      }
      goto LAB_00572f80;
    }
    if (pcVar11[1] != '\x02') {
      uVar25 = 0x75;
      uStack_5d0 = 0xac;
LAB_00573088:
      pcStack_5c0 = pcVar11;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x86,uVar25,FUN_0066c47c);
      goto LAB_00572f80;
    }
    pcStack_5c0 = pcVar11 + 0x10;
    uVar15 = (uint)(byte)pcVar11[9] << 8 | (uint)(byte)pcVar11[10] << 0x10 | (uint)(byte)pcVar11[8]
             | (uint)(byte)pcVar11[0xb] << 0x18;
    uVar24 = (uint)(byte)pcVar11[0xd] << 8 | (uint)(byte)pcVar11[0xe] << 0x10 |
             (uint)(byte)pcVar11[0xc] | (uint)(byte)pcVar11[0xf] << 0x18;
    if (uVar15 != 0x31535344) {
      if (uVar15 < 0x31535345) {
        if (uVar15 == 0x31415352) {
          if (uVar22 - 0x10 < (uVar24 + 7 >> 3) + 4) goto LAB_00573148;
          ppuVar12 = (undefined4 **)b2i_rsa_isra_1(&pcStack_5c0,uVar24,1);
          goto LAB_00572fa8;
        }
      }
      else if ((uVar15 == 0x32415352) || (uVar15 == 0x32535344)) {
        uVar25 = 0x78;
        uStack_5d0 = 0xc3;
        goto LAB_00573088;
      }
      uVar25 = 0x74;
      uStack_5d0 = 0xc9;
      goto LAB_00573088;
    }
    if (uVar22 - 0x10 < (uVar24 + 7 >> 3) * 3 + 0x2c) {
LAB_00573148:
      uStack_5d0 = 0xfd;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x84,0x7b,FUN_0066c47c);
      ppuVar12 = (undefined4 **)0x0;
    }
    else {
      ppuVar12 = (undefined4 **)b2i_dss_isra_0(&pcStack_5c0,uVar24,1);
    }
  }
LAB_00572fa8:
  if (ppuStack_5bc == *(undefined4 ***)puStack_600) {
    return ppuVar12;
  }
  pcStack_5e4 = b2i_PrivateKey_bio;
  ppuVar12 = ppuStack_5bc;
  (**(code **)(puStack_5c8 + -0x5330))();
  puStack_654 = PTR___stack_chk_guard_006a9ae8;
  ppuStack_658 = (undefined4 **)&cStack_614;
  puStack_620 = &_gp;
  puStack_5e8 = (undefined *)puVar6;
  puStack_604 = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  puStack_5f4 = puStack_64c;
  ppuStack_5f0 = ppuStack_6a8;
  ppuStack_5ec = ppuStack_6a4;
  iVar7 = (*(code *)PTR_BIO_read_006a74c0)();
  if (iVar7 == 0x10) {
    ppuStack_618 = ppuStack_658;
    if (cStack_614 == '\x06') {
      pcVar33 = *(code **)(puStack_620 + -0x6eac);
      uVar25 = 0x77;
      uStack_628 = 0x9d;
LAB_0057338c:
      (*pcVar33)(9,0x86,uVar25,FUN_0066c47c);
      goto LAB_00573204;
    }
    if (cStack_614 != '\a') goto LAB_00573204;
    if (cStack_613 != '\x02') {
      pcVar33 = *(code **)(puStack_620 + -0x6eac);
      uVar25 = 0x75;
      uStack_628 = 0xac;
      goto LAB_0057338c;
    }
    uVar15 = (((uStack_60c >> 0x10) << 0x18 | (uStack_60c >> 0x18) << 0x10) >> 0x10) +
             ((uStack_60c & 0xff) << 8 | uStack_60c >> 8 & 0xff) * 0x10000;
    ppuStack_6a4 = (undefined4 **)
                   ((((uStack_608 >> 0x10) << 0x18 | (uStack_608 >> 0x18) << 0x10) >> 0x10) +
                   ((uStack_608 & 0xff) << 8 | uStack_608 >> 8 & 0xff) * 0x10000);
    if (uVar15 == 0x31535344) {
LAB_00573378:
      pcVar33 = *(code **)(puStack_620 + -0x6eac);
      uVar25 = 0x77;
      uStack_628 = 0xba;
      goto LAB_0057338c;
    }
    if (uVar15 < 0x31535345) {
      if (uVar15 != 0x31415352) {
LAB_00573470:
        pcVar33 = *(code **)(puStack_620 + -0x6eac);
        uVar25 = 0x74;
        uStack_628 = 0xc9;
        goto LAB_0057338c;
      }
      goto LAB_00573378;
    }
    if (uVar15 == 0x32415352) {
      puStack_64c = (undefined *)0x0;
      ppuStack_658 = (undefined4 **)
                     ((((uint)((int)ppuStack_6a4 + 7) >> 3) + 2) * 2 +
                     ((uint)((int)ppuStack_6a4 + 0xf) >> 4) * 5);
    }
    else {
      puStack_64c = (undefined *)0x1;
      if (uVar15 != 0x32535344) goto LAB_00573470;
      ppuStack_658 = (undefined4 **)((((uint)((int)ppuStack_6a4 + 7) >> 3) + 0x20) * 2);
    }
    ppuStack_618 = &puStack_604;
    puVar6 = (undefined4 *)0x670000;
    if ((undefined4 **)0x19000 < ppuStack_658) {
      pcVar33 = *(code **)(puStack_620 + -0x6eac);
      uVar25 = 0x80;
      uStack_628 = 0x117;
      goto LAB_00573350;
    }
    ppuStack_6a8 = (undefined4 **)
                   (**(code **)(puStack_620 + -0x7dd8))(ppuStack_658,FUN_0066c47c,0x11a);
    if (ppuStack_6a8 == (undefined4 **)0x0) {
      uStack_628 = 0x11c;
      (**(code **)(puStack_620 + -0x6eac))(9,0x85,0x41,FUN_0066c47c);
      ppuVar13 = (undefined4 **)0x0;
    }
    else {
      ppuStack_618 = ppuStack_6a8;
      ppuVar13 = (undefined4 **)
                 (**(code **)(puStack_620 + -0x7920))(ppuVar12,ppuStack_6a8,ppuStack_658);
      if (ppuStack_658 == ppuVar13) {
        if (puStack_64c == (undefined *)0x0) {
          ppuVar13 = (undefined4 **)b2i_rsa_isra_1(&ppuStack_618,ppuStack_6a4,0);
        }
        else {
          ppuVar13 = (undefined4 **)b2i_dss_isra_0();
        }
      }
      else {
        uStack_628 = 0x121;
        ppuVar13 = (undefined4 **)0x0;
        (**(code **)(puStack_620 + -0x6eac))(9,0x85,0x7b,FUN_0066c47c);
      }
      (**(code **)(puStack_620 + -0x7f58))(ppuStack_6a8);
      ppuStack_658 = ppuVar13;
    }
  }
  else {
    pcVar33 = *(code **)(puStack_620 + -0x6eac);
    uVar25 = 0x7b;
    uStack_628 = 0x10e;
LAB_00573350:
    (*pcVar33)(9,0x85,uVar25,FUN_0066c47c);
LAB_00573204:
    ppuVar13 = (undefined4 **)0x0;
  }
  if (puStack_604 == *(undefined4 **)puStack_654) {
    return ppuVar13;
  }
  pcStack_63c = b2i_PublicKey_bio;
  puStack_6ac = puStack_604;
  (**(code **)(puStack_620 + -0x5330))();
  ppuVar13 = (undefined4 **)PTR___stack_chk_guard_006a9ae8;
  ppuVar23 = (undefined4 **)&SUB_00000010;
  ppuVar16 = (undefined4 **)&cStack_66c;
  puStack_678 = &_gp;
  puStack_65c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  ppuVar29 = ppuVar16;
  ppuStack_650 = ppuVar12;
  ppuStack_648 = ppuStack_6a8;
  ppuStack_644 = ppuStack_6a4;
  puStack_640 = puVar6;
  iVar7 = (*(code *)PTR_BIO_read_006a74c0)();
  if (iVar7 == 0x10) {
    ppuStack_670 = ppuVar16;
    if (cStack_66c != '\x06') {
      if (cStack_66c == '\a') {
        pcVar33 = *(code **)(puStack_678 + -0x6eac);
        ppuVar23 = (undefined4 **)&DAT_00000078;
        uStack_680 = 0xa3;
        goto LAB_005735cc;
      }
      goto LAB_00573528;
    }
    if (cStack_66b != '\x02') {
      pcVar33 = *(code **)(puStack_678 + -0x6eac);
      ppuVar23 = (undefined4 **)0x75;
      uStack_680 = 0xac;
LAB_005735cc:
      ppuVar29 = (undefined4 **)0x86;
      (*pcVar33)(9,0x86,ppuVar23,FUN_0066c47c);
      goto LAB_00573528;
    }
    uVar15 = (((uStack_664 >> 0x10) << 0x18 | (uStack_664 >> 0x18) << 0x10) >> 0x10) +
             ((uStack_664 & 0xff) << 8 | uStack_664 >> 8 & 0xff) * 0x10000;
    ppuVar12 = (undefined4 **)
               ((((uStack_660 >> 0x10) << 0x18 | (uStack_660 >> 0x18) << 0x10) >> 0x10) +
               ((uStack_660 & 0xff) << 8 | uStack_660 >> 8 & 0xff) * 0x10000);
    if (uVar15 != 0x31535344) {
      if (uVar15 < 0x31535345) {
        ppuStack_6a8 = (undefined4 **)0x0;
        if (uVar15 == 0x31415352) {
          ppuVar16 = (undefined4 **)(((uint)((int)ppuVar12 + 7) >> 3) + 4);
          goto LAB_00573630;
        }
      }
      else if ((uVar15 == 0x32415352) || (uVar15 == 0x32535344)) {
        pcVar33 = *(code **)(puStack_678 + -0x6eac);
        ppuVar23 = (undefined4 **)&DAT_00000078;
        uStack_680 = 0xc3;
        goto LAB_005735cc;
      }
      pcVar33 = *(code **)(puStack_678 + -0x6eac);
      ppuVar23 = (undefined4 **)&DAT_00000074;
      uStack_680 = 0xc9;
      goto LAB_005735cc;
    }
    ppuStack_6a8 = (undefined4 **)0x1;
    ppuVar16 = (undefined4 **)(((uint)((int)ppuVar12 + 7) >> 3) * 3 + 0x2c);
LAB_00573630:
    ppuStack_670 = &puStack_65c;
    puVar6 = (undefined4 *)0x670000;
    if ((undefined4 **)0x19000 < ppuVar16) {
      pcVar33 = *(code **)(puStack_678 + -0x6eac);
      ppuVar23 = (undefined4 **)&DAT_00000080;
      uStack_680 = 0x117;
      goto LAB_005735f8;
    }
    ppuStack_6a4 = (undefined4 **)(**(code **)(puStack_678 + -0x7dd8))(ppuVar16,FUN_0066c47c,0x11a);
    if (ppuStack_6a4 == (undefined4 **)0x0) {
      ppuVar23 = (undefined4 **)&DAT_00000041;
      ppuVar29 = (undefined4 **)0x85;
      uStack_680 = 0x11c;
      (**(code **)(puStack_678 + -0x6eac))(9,0x85,0x41,FUN_0066c47c);
      ppuVar14 = (undefined4 **)0x0;
    }
    else {
      ppuStack_670 = ppuStack_6a4;
      ppuVar29 = (undefined4 **)
                 (**(code **)(puStack_678 + -0x7920))(puStack_6ac,ppuStack_6a4,ppuVar16);
      if (ppuVar16 == ppuVar29) {
        ppuVar23 = (undefined4 **)0x1;
        ppuVar29 = ppuVar12;
        if (ppuStack_6a8 == (undefined4 **)0x0) {
          ppuVar14 = (undefined4 **)b2i_rsa_isra_1(&ppuStack_670);
        }
        else {
          ppuVar14 = (undefined4 **)b2i_dss_isra_0();
        }
      }
      else {
        ppuVar23 = (undefined4 **)0x7b;
        ppuVar29 = (undefined4 **)0x85;
        uStack_680 = 0x121;
        ppuVar14 = (undefined4 **)0x0;
        (**(code **)(puStack_678 + -0x6eac))(9,0x85,0x7b,FUN_0066c47c);
      }
      (**(code **)(puStack_678 + -0x7f58))(ppuStack_6a4);
      ppuVar16 = ppuVar14;
    }
  }
  else {
    pcVar33 = *(code **)(puStack_678 + -0x6eac);
    ppuVar23 = (undefined4 **)0x7b;
    uStack_680 = 0x10e;
LAB_005735f8:
    ppuVar29 = (undefined4 **)0x85;
    (*pcVar33)(9,0x85,ppuVar23,FUN_0066c47c);
LAB_00573528:
    ppuVar14 = (undefined4 **)0x0;
  }
  if (puStack_65c == *ppuVar13) {
    return ppuVar14;
  }
  pcStack_694 = i2b_PrivateKey_bio;
  puVar28 = puStack_65c;
  (**(code **)(puStack_678 + -0x5330))();
  puVar5 = PTR___stack_chk_guard_006a9ae8;
  puStack_6b4 = (undefined *)ppuVar13;
  puStack_6c0 = (undefined4 *)0x0;
  iStack_6bc = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppuStack_6b8 = ppuVar16;
  ppuStack_6b0 = ppuVar12;
  puStack_6a0 = puVar6;
  ppuStack_69c = unaff_s7;
  puStack_698 = unaff_s8;
  if (*ppuVar29 == (undefined4 *)0x74) {
    ppuVar16 = (undefined4 **)ppuVar29[5];
    ppuVar12 = (undefined4 **)(*(code *)PTR_BN_num_bits_006a71f4)(ppuVar16[3]);
    if ((((((uint)ppuVar12 & 7) != 0) ||
         (iVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(ppuVar16[4]), iVar7 != 0xa0)) ||
        (iVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(ppuVar16[5]), (int)ppuVar12 < iVar7)) ||
       (iVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(ppuVar16[7]), 0xa0 < iVar7)) {
      ppuVar23 = (undefined4 **)0x7e;
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x82,0x7e,FUN_0066c47c,0x222);
      goto LAB_00573fe8;
    }
    puStack_6c0 = (undefined4 *)0x32535344;
    if (ppuVar12 == (undefined4 **)0x0) goto LAB_00573fe8;
    unaff_s7 = (undefined4 **)0x22;
    puVar6 = (undefined4 *)0x2200;
    iVar7 = (((uint)((int)ppuVar12 + 7) >> 3) + 0x20) * 2;
  }
  else {
    ppuVar14 = (undefined4 **)0xffffffff;
    if (*ppuVar29 != (undefined4 *)0x6) goto LAB_00573f4c;
    ppuVar23 = &puStack_6c0;
    ppuVar12 = (undefined4 **)check_bitlen_rsa(ppuVar29[5],0);
    if (ppuVar12 == (undefined4 **)0x0) goto LAB_00573fe8;
    unaff_s7 = (undefined4 **)&DAT_000000a4;
    iVar7 = (((uint)((int)ppuVar12 + 7) >> 3) + 2) * 2 + ((uint)((int)ppuVar12 + 0xf) >> 4) * 5;
    puVar6 = (undefined4 *)0xa400;
  }
  ppuVar14 = (undefined4 **)(iVar7 + 0x10);
  ppuVar23 = (undefined4 **)0x1e8;
  ppuVar16 = (undefined4 **)(*(code *)PTR_CRYPTO_malloc_006a7008)(ppuVar14,FUN_0066c47c);
  ppuVar13 = ppuVar14;
  if (ppuVar16 == (undefined4 **)0x0) goto LAB_00573fe8;
  *(char *)((int)ppuVar16 + 2) = '\0';
  *(char *)((int)ppuVar16 + 3) = '\0';
  *(char *)(ppuVar16 + 1) = '\0';
  *(char *)((int)ppuVar16 + 5) = (char)unaff_s7;
  *(char *)((int)ppuVar16 + 6) = '\0';
  *(char *)ppuVar16 = '\a';
  ppuVar13 = ppuVar16 + 4;
  *(char *)((int)ppuVar16 + 7) = '\0';
  *(char *)(ppuVar16 + 3) = (char)ppuVar12;
  *(char *)((int)ppuVar16 + 1) = '\x02';
  *(char *)((int)ppuVar16 + 0xd) = (char)((uint)ppuVar12 >> 8);
  *(char *)((int)ppuVar16 + 0xe) = (char)((uint)ppuVar12 >> 0x10);
  *(char *)((int)ppuVar16 + 0xf) = (char)((uint)ppuVar12 >> 0x18);
  *(char *)(ppuVar16 + 2) = (char)puStack_6c0;
  *(char *)((int)ppuVar16 + 9) = (char)((uint)puStack_6c0 >> 8);
  *(char *)((int)ppuVar16 + 10) = (char)((uint)puStack_6c0 >> 0x10);
  *(char *)((int)ppuVar16 + 0xb) = (char)((uint)puStack_6c0 >> 0x18);
  if (puVar6 == (undefined4 *)0x2200) {
    puVar6 = ppuVar29[5];
    iVar17 = (*(code *)PTR_BN_num_bits_006a71f4)(puVar6[3]);
    uVar25 = puVar6[3];
    iVar7 = iVar17 + 7;
    if (iVar17 + 7 < 0) {
      iVar7 = iVar17 + 0xe;
    }
    iVar7 = iVar7 >> 3;
    iVar26 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar25);
    iVar27 = iVar26 + 7;
    iVar17 = iVar26 + 0xe;
    if (-1 < iVar27) {
      iVar17 = iVar27;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar25,ppuVar13);
    iVar17 = iVar17 >> 3;
    iVar26 = iVar26 + 0x16;
    if (-1 < iVar27) {
      iVar26 = iVar27;
    }
    if (0 < iVar26 >> 4) {
      ppuVar12 = ppuVar13;
      pcVar11 = (char *)((int)ppuVar13 + iVar17 + -1);
      do {
        cVar4 = *(char *)ppuVar12;
        ppuVar29 = (undefined4 **)((int)ppuVar12 + 1);
        *(char *)ppuVar12 = *pcVar11;
        *pcVar11 = cVar4;
        ppuVar12 = ppuVar29;
        pcVar11 = pcVar11 + -1;
      } while ((undefined4 **)((int)ppuVar13 + (iVar26 >> 4)) != ppuVar29);
    }
    pcVar32 = (char *)((int)ppuVar13 + iVar17);
    pcVar11 = pcVar32;
    if ((0 < iVar7) && (0 < iVar7 - iVar17)) {
      pcVar11 = pcVar32 + (iVar7 - iVar17);
      (*(code *)PTR_memset_006a99f4)(pcVar32,0);
    }
    uVar25 = puVar6[4];
    iVar26 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar25);
    iVar27 = iVar26 + 7;
    iVar17 = iVar26 + 0xe;
    if (-1 < iVar27) {
      iVar17 = iVar27;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar25,pcVar11);
    iVar17 = iVar17 >> 3;
    iVar26 = iVar26 + 0x16;
    if (-1 < iVar27) {
      iVar26 = iVar27;
    }
    if (0 < iVar26 >> 4) {
      pcVar32 = pcVar11;
      pcVar20 = pcVar11 + iVar17 + -1;
      do {
        cVar4 = *pcVar32;
        pcVar19 = pcVar32 + 1;
        *pcVar32 = *pcVar20;
        *pcVar20 = cVar4;
        pcVar32 = pcVar19;
        pcVar20 = pcVar20 + -1;
      } while (pcVar11 + (iVar26 >> 4) != pcVar19);
    }
    pcVar11 = pcVar11 + iVar17;
    pcVar32 = pcVar11;
    if (0 < 0x14 - iVar17) {
      pcVar32 = pcVar11 + (0x14 - iVar17);
      (*(code *)PTR_memset_006a99f4)(pcVar11,0);
    }
    uVar25 = puVar6[5];
    iVar27 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar25);
    iVar26 = iVar27 + 7;
    iVar17 = iVar27 + 0xe;
    if (-1 < iVar26) {
      iVar17 = iVar26;
    }
    iVar17 = iVar17 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar25,pcVar32);
    if (-1 >= iVar26) {
      iVar26 = iVar27 + 0x16;
    }
    if (0 < iVar26 >> 4) {
      pcVar11 = pcVar32;
      pcVar20 = pcVar32 + iVar17 + -1;
      do {
        cVar4 = *pcVar11;
        pcVar19 = pcVar11 + 1;
        *pcVar11 = *pcVar20;
        *pcVar20 = cVar4;
        pcVar11 = pcVar19;
        pcVar20 = pcVar20 + -1;
      } while (pcVar19 != pcVar32 + (iVar26 >> 4));
    }
    ppuVar12 = (undefined4 **)(pcVar32 + iVar17);
    unaff_s7 = ppuVar12;
    if ((0 < iVar7) && (0 < iVar7 - iVar17)) {
      unaff_s7 = (undefined4 **)((int)ppuVar12 + (iVar7 - iVar17));
      (*(code *)PTR_memset_006a99f4)(ppuVar12,0);
    }
    uVar25 = puVar6[7];
    iVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar25);
    puVar10 = (undefined4 *)(iVar7 + 7);
    puVar30 = (undefined4 *)(iVar7 + 0xe);
    if (-1 < (int)puVar10) {
      puVar30 = puVar10;
    }
    puVar6 = (undefined4 *)(iVar7 + 0x16);
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar25,unaff_s7);
    if (-1 >= (int)puVar10) {
      puVar10 = puVar6;
    }
    ppuVar29 = (undefined4 **)((int)puVar30 >> 3);
    if (0 < (int)puVar10 >> 4) {
      ppuVar12 = unaff_s7;
      pcVar11 = (char *)((int)unaff_s7 + (int)((int)ppuVar29 + -1));
      do {
        cVar4 = *(char *)ppuVar12;
        ppuVar13 = (undefined4 **)((int)ppuVar12 + 1);
        *(char *)ppuVar12 = *pcVar11;
        *pcVar11 = cVar4;
        ppuVar12 = ppuVar13;
        pcVar11 = pcVar11 + -1;
      } while (ppuVar13 != (undefined4 **)((int)unaff_s7 + ((int)puVar10 >> 4)));
    }
    ppuVar13 = (undefined4 **)((int)unaff_s7 + (int)ppuVar29);
    ppuVar12 = ppuVar13;
    if (0 < 0x14 - (int)ppuVar29) {
      ppuVar12 = (undefined4 **)((int)ppuVar13 + (0x14 - (int)ppuVar29));
      (*(code *)PTR_memset_006a99f4)(ppuVar13,0);
    }
    ppuVar23 = (undefined4 **)&DAT_00000018;
    (*(code *)PTR_memset_006a99f4)(ppuVar12,0xff);
    ppuVar18 = ppuVar16;
    goto LAB_00573f14;
  }
  puVar6 = ppuVar29[5];
  iVar17 = (*(code *)PTR_BN_num_bits_006a71f4)(puVar6[4]);
  iVar7 = iVar17 + 7;
  if (iVar17 + 7 < 0) {
    iVar7 = iVar17 + 0xe;
  }
  ppuVar29 = (undefined4 **)(iVar7 >> 3);
  iVar7 = (*(code *)PTR_BN_num_bits_006a71f4)(puVar6[4]);
  uVar25 = puVar6[5];
  ppuVar12 = (undefined4 **)(iVar7 + 0xf >> 4);
  iVar17 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar25);
  iVar26 = iVar17 + 7;
  iVar7 = iVar17 + 0xe;
  if (-1 < iVar26) {
    iVar7 = iVar26;
  }
  iVar7 = iVar7 >> 3;
  (*(code *)PTR_BN_bn2bin_006a7200)(uVar25,ppuVar13);
  iVar17 = iVar17 + 0x16;
  if (-1 < iVar26) {
    iVar17 = iVar26;
  }
  if (0 < iVar17 >> 4) {
    ppuVar23 = ppuVar13;
    pcVar11 = (char *)((int)ppuVar13 + iVar7 + -1);
    do {
      cVar4 = *(char *)ppuVar23;
      ppuVar18 = (undefined4 **)((int)ppuVar23 + 1);
      *(char *)ppuVar23 = *pcVar11;
      *pcVar11 = cVar4;
      ppuVar23 = ppuVar18;
      pcVar11 = pcVar11 + -1;
    } while ((undefined4 **)((int)ppuVar13 + (iVar17 >> 4)) != ppuVar18);
  }
  pcVar32 = (char *)((int)ppuVar13 + iVar7);
  pcVar11 = pcVar32;
  if (0 < 4 - iVar7) {
    pcVar11 = pcVar32 + (4 - iVar7);
    (*(code *)PTR_memset_006a99f4)(pcVar32,0);
  }
  uVar25 = puVar6[4];
  iVar26 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar25);
  iVar17 = iVar26 + 7;
  (*(code *)PTR_BN_bn2bin_006a7200)(uVar25,pcVar11);
  iVar7 = iVar17;
  if (iVar17 < 0) {
    iVar17 = iVar26 + 0x16;
    iVar7 = iVar26 + 0xe;
  }
  if (0 < iVar17 >> 4) {
    pcVar32 = pcVar11;
    pcVar20 = pcVar11 + (iVar7 >> 3) + -1;
    do {
      cVar4 = *pcVar32;
      pcVar19 = pcVar32 + 1;
      *pcVar32 = *pcVar20;
      *pcVar20 = cVar4;
      pcVar32 = pcVar19;
      pcVar20 = pcVar20 + -1;
    } while (pcVar19 != pcVar11 + (iVar17 >> 4));
  }
  uVar25 = puVar6[7];
  pcVar11 = pcVar11 + (iVar7 >> 3);
  iVar17 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar25);
  iVar26 = iVar17 + 7;
  iVar7 = iVar17 + 0xe;
  if (-1 < iVar26) {
    iVar7 = iVar26;
  }
  iVar7 = iVar7 >> 3;
  (*(code *)PTR_BN_bn2bin_006a7200)(uVar25,pcVar11);
  iVar17 = iVar17 + 0x16;
  if (-1 < iVar26) {
    iVar17 = iVar26;
  }
  if (0 < iVar17 >> 4) {
    pcVar32 = pcVar11;
    pcVar20 = pcVar11 + iVar7 + -1;
    do {
      cVar4 = *pcVar32;
      pcVar19 = pcVar32 + 1;
      *pcVar32 = *pcVar20;
      *pcVar20 = cVar4;
      pcVar32 = pcVar19;
      pcVar20 = pcVar20 + -1;
    } while (pcVar11 + (iVar17 >> 4) != pcVar19);
  }
  pcVar11 = pcVar11 + iVar7;
  if ((int)ppuVar12 < 1) {
    uVar25 = puVar6[8];
    iVar17 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar25);
    iVar26 = iVar17 + 7;
    iVar7 = iVar17 + 0xe;
    if (-1 < iVar26) {
      iVar7 = iVar26;
    }
    iVar7 = iVar7 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar25,pcVar11);
    iVar17 = iVar17 + 0x16;
    if (-1 < iVar26) {
      iVar17 = iVar26;
    }
    iVar17 = iVar17 >> 4;
    pcVar32 = pcVar11 + iVar7 + -1;
    if (0 < iVar17) goto LAB_00573bc8;
    pcVar11 = pcVar11 + iVar7;
LAB_00574388:
    uVar25 = puVar6[9];
    iVar17 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar25);
    iVar26 = iVar17 + 7;
    iVar7 = iVar17 + 0xe;
    if (-1 < iVar26) {
      iVar7 = iVar26;
    }
    iVar7 = iVar7 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar25,pcVar11);
    iVar17 = iVar17 + 0x16;
    if (-1 < iVar26) {
      iVar17 = iVar26;
    }
    iVar17 = iVar17 >> 4;
    pcVar32 = pcVar11 + iVar7 + -1;
    if (0 < iVar17) goto LAB_00573c8c;
    pcVar11 = pcVar11 + iVar7;
LAB_00574400:
    uVar25 = puVar6[10];
    iVar26 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar25);
    iVar7 = iVar26 + 7;
    iVar17 = iVar26 + 0xe;
    if (-1 < iVar7) {
      iVar17 = iVar7;
    }
    iVar17 = iVar17 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar25,pcVar11);
    if (-1 >= iVar7) {
      iVar7 = iVar26 + 0x16;
    }
    iVar7 = iVar7 >> 4;
    pcVar32 = pcVar11 + iVar17 + -1;
    if (0 < iVar7) goto LAB_00573d50;
LAB_00573d74:
    unaff_s7 = (undefined4 **)(pcVar11 + iVar17);
    if ((int)ppuVar12 < 1) {
      uVar25 = puVar6[0xb];
      iVar26 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar25);
      iVar17 = iVar26 + 7;
      iVar7 = iVar26 + 0xe;
      if (-1 < iVar17) {
        iVar7 = iVar17;
      }
      ppuVar23 = (undefined4 **)(iVar7 >> 3);
      (*(code *)PTR_BN_bn2bin_006a7200)(uVar25,unaff_s7);
      if (-1 >= iVar17) {
        iVar17 = iVar26 + 0x16;
      }
      iVar17 = iVar17 >> 4;
      pcVar11 = (char *)((int)unaff_s7 + (int)((int)ppuVar23 + -1));
      if (iVar17 < 1) {
        unaff_s7 = (undefined4 **)((int)unaff_s7 + (int)ppuVar23);
        goto LAB_00573e60;
      }
      goto LAB_00573e14;
    }
  }
  else {
    iVar7 = (int)ppuVar12 - iVar7;
    if (0 < iVar7) {
      (*(code *)PTR_memset_006a99f4)(pcVar11,0,iVar7);
      pcVar11 = pcVar11 + iVar7;
    }
    uVar25 = puVar6[8];
    iVar17 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar25);
    iVar26 = iVar17 + 7;
    iVar7 = iVar17 + 0xe;
    if (-1 < iVar26) {
      iVar7 = iVar26;
    }
    iVar7 = iVar7 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar25,pcVar11);
    iVar17 = iVar17 + 0x16;
    if (-1 < iVar26) {
      iVar17 = iVar26;
    }
    iVar17 = iVar17 >> 4;
    pcVar32 = pcVar11 + iVar7 + -1;
    if (iVar17 < 1) {
      pcVar11 = pcVar11 + iVar7;
    }
    else {
LAB_00573bc8:
      pcVar20 = pcVar11;
      do {
        cVar4 = *pcVar20;
        pcVar19 = pcVar20 + 1;
        *pcVar20 = *pcVar32;
        *pcVar32 = cVar4;
        pcVar20 = pcVar19;
        pcVar32 = pcVar32 + -1;
      } while (pcVar11 + iVar17 != pcVar19);
      pcVar11 = pcVar11 + iVar7;
      if ((int)ppuVar12 < 1) goto LAB_00574388;
    }
    iVar7 = (int)ppuVar12 - iVar7;
    if (0 < iVar7) {
      (*(code *)PTR_memset_006a99f4)(pcVar11,0,iVar7);
      pcVar11 = pcVar11 + iVar7;
    }
    uVar25 = puVar6[9];
    iVar17 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar25);
    iVar26 = iVar17 + 7;
    iVar7 = iVar17 + 0xe;
    if (-1 < iVar26) {
      iVar7 = iVar26;
    }
    iVar7 = iVar7 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar25,pcVar11);
    iVar17 = iVar17 + 0x16;
    if (-1 < iVar26) {
      iVar17 = iVar26;
    }
    iVar17 = iVar17 >> 4;
    pcVar32 = pcVar11 + iVar7 + -1;
    if (iVar17 < 1) {
      pcVar11 = pcVar11 + iVar7;
    }
    else {
LAB_00573c8c:
      pcVar20 = pcVar11;
      do {
        cVar4 = *pcVar20;
        pcVar19 = pcVar20 + 1;
        *pcVar20 = *pcVar32;
        *pcVar32 = cVar4;
        pcVar20 = pcVar19;
        pcVar32 = pcVar32 + -1;
      } while (pcVar11 + iVar17 != pcVar19);
      pcVar11 = pcVar11 + iVar7;
      if ((int)ppuVar12 < 1) goto LAB_00574400;
    }
    iVar7 = (int)ppuVar12 - iVar7;
    if (0 < iVar7) {
      (*(code *)PTR_memset_006a99f4)(pcVar11,0,iVar7);
      pcVar11 = pcVar11 + iVar7;
    }
    uVar25 = puVar6[10];
    iVar26 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar25);
    iVar7 = iVar26 + 7;
    iVar17 = iVar26 + 0xe;
    if (-1 < iVar7) {
      iVar17 = iVar7;
    }
    iVar17 = iVar17 >> 3;
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar25,pcVar11);
    if (-1 >= iVar7) {
      iVar7 = iVar26 + 0x16;
    }
    iVar7 = iVar7 >> 4;
    pcVar32 = pcVar11 + iVar17 + -1;
    if (0 < iVar7) {
LAB_00573d50:
      pcVar20 = pcVar11;
      do {
        cVar4 = *pcVar20;
        pcVar19 = pcVar20 + 1;
        *pcVar20 = *pcVar32;
        *pcVar32 = cVar4;
        pcVar32 = pcVar32 + -1;
        pcVar20 = pcVar19;
      } while (pcVar11 + iVar7 != pcVar19);
      goto LAB_00573d74;
    }
    unaff_s7 = (undefined4 **)(pcVar11 + iVar17);
  }
  iVar17 = (int)ppuVar12 - iVar17;
  if (0 < iVar17) {
    (*(code *)PTR_memset_006a99f4)(unaff_s7,0,iVar17);
    unaff_s7 = (undefined4 **)((int)unaff_s7 + iVar17);
  }
  uVar25 = puVar6[0xb];
  iVar26 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar25);
  iVar17 = iVar26 + 7;
  iVar7 = iVar26 + 0xe;
  if (-1 < iVar17) {
    iVar7 = iVar17;
  }
  ppuVar23 = (undefined4 **)(iVar7 >> 3);
  (*(code *)PTR_BN_bn2bin_006a7200)(uVar25,unaff_s7);
  if (-1 >= iVar17) {
    iVar17 = iVar26 + 0x16;
  }
  iVar17 = iVar17 >> 4;
  pcVar11 = (char *)((int)unaff_s7 + (int)((int)ppuVar23 + -1));
  if (iVar17 < 1) goto LAB_00574578;
LAB_00573e14:
  ppuVar13 = unaff_s7;
  do {
    cVar4 = *(char *)ppuVar13;
    ppuVar18 = (undefined4 **)((int)ppuVar13 + 1);
    *(char *)ppuVar13 = *pcVar11;
    *pcVar11 = cVar4;
    pcVar11 = pcVar11 + -1;
    ppuVar13 = ppuVar18;
  } while ((undefined4 **)((int)unaff_s7 + iVar17) != ppuVar18);
  ppuVar13 = (undefined4 **)((int)unaff_s7 + (int)ppuVar23);
  unaff_s7 = ppuVar13;
  if ((int)ppuVar12 < 1) goto LAB_00573e60;
  do {
    unaff_s7 = ppuVar13;
    if (0 < (int)ppuVar12 - (int)ppuVar23) {
      unaff_s7 = (undefined4 **)((int)ppuVar13 + ((int)ppuVar12 - (int)ppuVar23));
      (*(code *)PTR_memset_006a99f4)(ppuVar13,0);
    }
LAB_00573e60:
    uVar25 = puVar6[6];
    iVar26 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar25);
    iVar7 = iVar26 + 7;
    ppuVar12 = (undefined4 **)(uint)(iVar7 < 0);
    iVar17 = iVar26 + 0xe;
    if (ppuVar12 == (undefined4 **)0x0) {
      iVar17 = iVar7;
    }
    (*(code *)PTR_BN_bn2bin_006a7200)(uVar25,unaff_s7);
    puVar6 = (undefined4 *)(iVar17 >> 3);
    if (ppuVar12 != (undefined4 **)0x0) {
      iVar7 = iVar26 + 0x16;
    }
    ppuVar23 = (undefined4 **)(iVar7 >> 4);
    if (0 < (int)ppuVar23) {
      ppuVar23 = (undefined4 **)((int)unaff_s7 + (int)ppuVar23);
      pcVar11 = (char *)((int)unaff_s7 + (int)((int)puVar6 + -1));
      ppuVar13 = unaff_s7;
      do {
        cVar4 = *(char *)ppuVar13;
        ppuVar18 = (undefined4 **)((int)ppuVar13 + 1);
        *(char *)ppuVar13 = *pcVar11;
        *pcVar11 = cVar4;
        pcVar11 = pcVar11 + -1;
        ppuVar13 = ppuVar18;
      } while (ppuVar23 != ppuVar18);
    }
    ppuVar18 = ppuVar16;
    if ((0 < (int)ppuVar29) &&
       (ppuVar23 = (undefined4 **)((int)ppuVar29 - (int)puVar6), 0 < (int)ppuVar23)) {
      (*(code *)PTR_memset_006a99f4)((char *)((int)unaff_s7 + (int)puVar6),0);
    }
LAB_00573f14:
    ppuVar16 = ppuVar18;
    ppuVar13 = ppuVar14;
    if ((int)ppuVar14 < 0) {
LAB_00573fe8:
      ppuVar14 = (undefined4 **)0xffffffff;
    }
    else {
      ppuVar23 = ppuVar14;
      ppuVar16 = (undefined4 **)(*(code *)PTR_BIO_write_006a6e14)(puVar28,ppuVar18);
      (*(code *)PTR_CRYPTO_free_006a6e88)(ppuVar18);
      if (ppuVar16 != ppuVar14) goto LAB_00573fe8;
    }
LAB_00573f4c:
    if (iStack_6bc == *(int *)puVar5) {
      return ppuVar14;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    ppuVar14 = ppuVar13;
LAB_00574578:
    ppuVar13 = (undefined4 **)((int)unaff_s7 + (int)ppuVar23);
  } while( true );
}

