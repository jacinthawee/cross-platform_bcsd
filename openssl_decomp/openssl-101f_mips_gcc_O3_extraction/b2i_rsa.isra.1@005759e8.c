
int * b2i_rsa_isra_1(byte **param_1,uint param_2,byte *param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  char cVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 ****ppppuVar7;
  undefined4 ****ppppuVar8;
  int *piVar9;
  int *piVar10;
  char *pcVar11;
  int *piVar12;
  uint uVar13;
  int *piVar14;
  int iVar15;
  char *pcVar16;
  char *pcVar17;
  int iVar18;
  int *piVar19;
  char **ppcVar20;
  uint uVar21;
  int *piVar22;
  uint uVar23;
  undefined4 uVar24;
  int iVar25;
  int iVar26;
  undefined4 ****unaff_s1;
  int iVar27;
  byte *pbVar28;
  char *pcVar29;
  char *unaff_s7;
  int *piVar30;
  char *pcVar31;
  char *pcVar32;
  code *pcVar33;
  int *unaff_s8;
  int iStack_6c0;
  int iStack_6bc;
  int *piStack_6b8;
  int *piStack_6b4;
  undefined *puStack_6b0;
  int iStack_6ac;
  int *piStack_6a8;
  int iStack_6a4;
  char *pcStack_6a0;
  char *pcStack_69c;
  int *piStack_698;
  code *pcStack_694;
  undefined4 uStack_680;
  undefined *puStack_678;
  int *piStack_670;
  char cStack_66c;
  char cStack_66b;
  uint uStack_664;
  uint uStack_660;
  int iStack_65c;
  int *piStack_658;
  undefined *puStack_654;
  uint uStack_650;
  int iStack_64c;
  int *piStack_648;
  int iStack_644;
  char *pcStack_640;
  code *pcStack_63c;
  undefined4 uStack_628;
  undefined *puStack_620;
  int *piStack_618;
  char cStack_614;
  char cStack_613;
  uint uStack_60c;
  uint uStack_608;
  int iStack_604;
  undefined *puStack_600;
  code *pcStack_5fc;
  uint uStack_5f8;
  int **ppiStack_5f4;
  int *piStack_5f0;
  int iStack_5ec;
  undefined *puStack_5e8;
  code *pcStack_5e4;
  undefined4 uStack_5d0;
  undefined *puStack_5c8;
  char *pcStack_5c0;
  int iStack_5bc;
  undefined *puStack_5b4;
  int *piStack_5b0;
  code *pcStack_5ac;
  undefined4 uStack_598;
  undefined *puStack_590;
  char *pcStack_588;
  char **ppcStack_584;
  int *piStack_57c;
  int *piStack_578;
  code *pcStack_574;
  int iStack_560;
  undefined *puStack_558;
  int *piStack_54c;
  int iStack_548;
  int *piStack_544;
  int *apiStack_53c [6];
  int aiStack_524 [35];
  int iStack_498;
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
  int aiStack_484 [256];
  char **ppcStack_84;
  int *piStack_80;
  undefined4 ****ppppuStack_7c;
  int iStack_78;
  undefined *puStack_74;
  byte **ppbStack_70;
  uint uStack_6c;
  byte *pbStack_68;
  char *pcStack_64;
  int *piStack_60;
  code *pcStack_5c;
  int **local_48;
  undefined *local_40;
  int *local_34;
  undefined4 ****local_30;
  int *local_2c;
  
  puStack_74 = PTR___stack_chk_guard_006aabf0;
  local_30 = (undefined4 ****)*param_1;
  local_40 = &_gp;
  local_2c = *(int **)PTR___stack_chk_guard_006aabf0;
  iStack_78 = (*(code *)PTR_RSA_new_006a8964)();
  piStack_80 = (int *)(**(code **)(local_40 + -0x77d0))();
  if (iStack_78 == 0) {
    uStack_650 = 0x41;
    pcStack_5fc = FUN_0066ce6c;
    local_48 = (int **)0x19b;
    iStack_6a4 = 0x81;
    (**(code **)(local_40 + -0x6eb0))(9);
LAB_00575b04:
    if (piStack_80 == (int *)0x0) {
      piVar30 = (int *)0x0;
    }
    else {
      (**(code **)(local_40 + -0x7f68))(piStack_80);
      piVar30 = (int *)0x0;
    }
  }
  else {
    if (piStack_80 == (int *)0x0) {
LAB_00575ad0:
      unaff_s7 = "7 datafinal";
      pcStack_5fc = FUN_0066ce6c;
      uStack_650 = 0x41;
      iStack_6a4 = 0x81;
      local_48 = (int **)0x19b;
      (**(code **)(local_40 + -0x6eb0))(9);
      (**(code **)(local_40 + -0x77f0))(iStack_78);
      goto LAB_00575b04;
    }
    iVar6 = (**(code **)(local_40 + -0x7c2c))();
    *(int *)(iStack_78 + 0x14) = iVar6;
    if (iVar6 == 0) goto LAB_00575ad0;
    pbVar28 = (byte *)((int)local_30 + 1);
    pbVar1 = (byte *)((int)local_30 + 2);
    pbVar2 = (byte *)((int)local_30 + 3);
    bVar3 = *(byte *)local_30;
    local_30 = local_30 + 1;
    iVar6 = (**(code **)(local_40 + -0x76c0))
                      (iVar6,(uint)*pbVar2 << 0x18 |
                             (uint)*pbVar28 << 8 | (uint)*pbVar1 << 0x10 | (uint)bVar3);
    if (iVar6 == 0) goto LAB_00575ad0;
    unaff_s7 = "7 datafinal";
    unaff_s8 = (int *)(param_2 + 7 >> 3);
    unaff_s1 = (undefined4 ****)((int)local_30 + (int)((int)unaff_s8 + -1));
    piVar30 = (int *)(**(code **)(local_40 + -0x7dd8))(unaff_s8,FUN_0066ce6c,0x60);
    if (piVar30 == (int *)0x0) goto LAB_00575ad0;
    pcVar33 = *(code **)(local_40 + -0x74f0);
    if (unaff_s8 != (int *)0x0) {
      piVar9 = piVar30;
      ppppuVar7 = unaff_s1;
      do {
        unaff_s1 = (undefined4 ****)((int)ppppuVar7 + -1);
        piVar10 = (int *)((int)piVar9 + 1);
        *(byte *)piVar9 = *(byte *)ppppuVar7;
        piVar9 = piVar10;
        ppppuVar7 = unaff_s1;
      } while (piVar10 != (int *)((int)piVar30 + (int)unaff_s8));
      pcVar33 = *(code **)(local_40 + -0x74f0);
    }
    uStack_650 = 0;
    local_34 = piVar30;
    uVar24 = (*pcVar33)(piVar30,unaff_s8);
    *(undefined4 *)(iStack_78 + 0x10) = uVar24;
    pcStack_5fc = (code *)local_34;
    (**(code **)(local_40 + -0x7f58))(local_34);
    if (*(int *)(iStack_78 + 0x10) == 0) goto LAB_00575ad0;
    unaff_s1 = (undefined4 ****)((int)local_30 + (int)unaff_s8);
    local_30 = unaff_s1;
    if (param_3 == (byte *)0x0) {
      param_2 = param_2 + 0xf >> 4;
      param_3 = (byte *)(param_2 - 1);
      piVar30 = (int *)(**(code **)(local_40 + -0x7dd8))(param_2,FUN_0066ce6c,0x60);
      unaff_s1 = (undefined4 ****)((int)unaff_s1 + (int)param_3);
      if (piVar30 != (int *)0x0) {
        pcVar33 = *(code **)(local_40 + -0x74f0);
        if (param_2 != 0) {
          piVar9 = piVar30;
          ppppuVar7 = unaff_s1;
          do {
            unaff_s1 = (undefined4 ****)((int)ppppuVar7 + -1);
            piVar10 = (int *)((int)piVar9 + 1);
            *(byte *)piVar9 = *(byte *)ppppuVar7;
            piVar9 = piVar10;
            ppppuVar7 = unaff_s1;
          } while (piVar10 != (int *)((int)piVar30 + param_2));
          pcVar33 = *(code **)(local_40 + -0x74f0);
        }
        local_34 = piVar30;
        uVar24 = (*pcVar33)(piVar30,param_2,0);
        *(undefined4 *)(iStack_78 + 0x1c) = uVar24;
        (**(code **)(local_40 + -0x7f58))(local_34);
        if (*(int *)(iStack_78 + 0x1c) != 0) {
          local_30 = (undefined4 ****)((int)local_30 + param_2);
          unaff_s1 = (undefined4 ****)((int)local_30 + (int)param_3);
          piVar30 = (int *)(**(code **)(local_40 + -0x7dd8))(param_2,FUN_0066ce6c,0x60);
          if (piVar30 != (int *)0x0) {
            pcVar33 = *(code **)(local_40 + -0x74f0);
            if (param_2 != 0) {
              piVar9 = piVar30;
              ppppuVar7 = unaff_s1;
              do {
                unaff_s1 = (undefined4 ****)((int)ppppuVar7 + -1);
                piVar10 = (int *)((int)piVar9 + 1);
                *(byte *)piVar9 = *(byte *)ppppuVar7;
                piVar9 = piVar10;
                ppppuVar7 = unaff_s1;
              } while (piVar10 != (int *)((int)piVar30 + param_2));
              pcVar33 = *(code **)(local_40 + -0x74f0);
            }
            local_34 = piVar30;
            uVar24 = (*pcVar33)(piVar30,param_2,0);
            *(undefined4 *)(iStack_78 + 0x20) = uVar24;
            pcStack_5fc = (code *)local_34;
            (**(code **)(local_40 + -0x7f58))(local_34);
            if (*(int *)(iStack_78 + 0x20) != 0) {
              local_30 = (undefined4 ****)((int)local_30 + param_2);
              param_3 = (byte *)((int)local_30 + (int)param_3);
              unaff_s1 = (undefined4 ****)
                         (**(code **)(local_40 + -0x7dd8))(param_2,FUN_0066ce6c,0x60);
              if (unaff_s1 != (undefined4 ****)0x0) {
                ppppuVar7 = unaff_s1;
                pbVar28 = param_3;
                if (param_2 != 0) {
                  do {
                    param_3 = pbVar28 + -1;
                    ppppuVar8 = (undefined4 ****)((int)ppppuVar7 + 1);
                    *(byte *)ppppuVar7 = *pbVar28;
                    ppppuVar7 = ppppuVar8;
                    pbVar28 = param_3;
                  } while ((undefined4 ****)((int)unaff_s1 + param_2) != ppppuVar8);
                }
                uVar24 = (**(code **)(local_40 + -0x74f0))(unaff_s1,param_2,0);
                pcVar33 = *(code **)(local_40 + -0x7f58);
                *(undefined4 *)(iStack_78 + 0x24) = uVar24;
                (*pcVar33)(unaff_s1);
                if (*(int *)(iStack_78 + 0x24) != 0) {
                  unaff_s1 = &local_30;
                  local_30 = (undefined4 ****)((int)local_30 + param_2);
                  iVar6 = read_lebn(unaff_s1,param_2,iStack_78 + 0x28);
                  if ((iVar6 != 0) &&
                     (iVar6 = read_lebn(unaff_s1,param_2,iStack_78 + 0x2c), iVar6 != 0)) {
                    uStack_650 = iStack_78 + 0x18;
                    iVar6 = read_lebn(unaff_s1,unaff_s8);
                    if (iVar6 != 0) goto LAB_00575df4;
                  }
                }
              }
            }
          }
        }
      }
      goto LAB_00575ad0;
    }
LAB_00575df4:
    iStack_6a4 = iStack_78;
    (**(code **)(local_40 + -0x77cc))(piStack_80);
    (**(code **)(local_40 + -0x77f0))(iStack_78);
    *param_1 = (byte *)local_30;
    piVar30 = piStack_80;
  }
  if (local_2c == *(int **)puStack_74) {
    return piVar30;
  }
  pcStack_5c = do_PVK_body_isra_3;
  piStack_57c = local_2c;
  (**(code **)(local_40 + -0x5328))();
  ppiStack_5f4 = local_48;
  pcVar29 = PTR___stack_chk_guard_006aabf0;
  piStack_6a8 = aiStack_524;
  puStack_558 = &_gp;
  ppcStack_84 = *(char ***)PTR___stack_chk_guard_006aabf0;
  ppppuStack_7c = unaff_s1;
  ppbStack_70 = param_1;
  uStack_6c = param_2;
  pbStack_68 = param_3;
  pcStack_64 = unaff_s7;
  piStack_60 = unaff_s8;
  (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(piStack_6a8);
  if (iStack_6a4 == 0) {
    pcStack_5fc = (code *)piStack_57c;
    piVar30 = (int *)0x0;
    goto LAB_0057606c;
  }
  piStack_54c = aiStack_484;
  if ((int *)pcStack_5fc == (int *)0x0) {
    unaff_s8 = (int *)PEM_def_callback((char *)piStack_54c,0x400,0,ppiStack_5f4);
  }
  else {
    unaff_s8 = (int *)(*pcStack_5fc)(piStack_54c,0x400,0,ppiStack_5f4);
  }
  if ((int)unaff_s8 < 1) {
    iStack_560 = 0x2ea;
    piVar9 = (int *)0x87;
    (**(code **)(puStack_558 + -0x6eb0))(9,0x87,0x68,FUN_0066ce6c);
    piVar10 = (int *)0x0;
  }
  else {
    pcStack_5fc = (code *)(**(code **)(puStack_558 + -0x7dd8))(uStack_650 + 8,FUN_0066ce6c,0x2ed);
    if ((int *)pcStack_5fc == (int *)0x0) {
      piVar9 = (int *)0x87;
      iStack_560 = 0x2f0;
      (**(code **)(puStack_558 + -0x6eb0))(9,0x87,0x41,FUN_0066ce6c);
      piVar10 = (int *)0x0;
    }
    else {
      ppiStack_5f4 = apiStack_53c;
      (**(code **)(puStack_558 + -0x7fc4))(ppiStack_5f4);
      piVar9 = (int *)(**(code **)(puStack_558 + -0x781c))();
      iVar6 = (**(code **)(puStack_558 + -0x7870))(ppiStack_5f4,piVar9,0);
      if (((iVar6 != 0) &&
          (piVar9 = piStack_57c,
          iVar6 = (**(code **)(puStack_558 + -0x786c))(ppiStack_5f4,piStack_57c,iStack_6a4),
          iVar6 != 0)) &&
         (piVar9 = piStack_54c,
         iVar6 = (**(code **)(puStack_558 + -0x786c))(ppiStack_5f4,piStack_54c,unaff_s8), iVar6 != 0
         )) {
        unaff_s8 = &iStack_498;
        piVar9 = unaff_s8;
        iVar6 = (**(code **)(puStack_558 + -0x7868))(ppiStack_5f4,unaff_s8,0);
        if (iVar6 != 0) {
          piStack_57c = (int *)((int)piStack_57c + iStack_6a4);
          (**(code **)(puStack_558 + -0x7fac))(ppiStack_5f4);
          iVar6 = piStack_57c[1];
          pcVar33 = *(code **)(puStack_558 + -0x69b8);
          *(int *)pcStack_5fc = *piStack_57c;
          *(int *)((int)pcStack_5fc + 4) = iVar6;
          piVar9 = (int *)(*pcVar33)();
          iStack_560 = 0;
          iVar6 = (**(code **)(puStack_558 + -0x738c))(piStack_6a8,piVar9,0,unaff_s8);
          piVar30 = (int *)pcStack_5fc;
          if (iVar6 == 0) {
LAB_0057603c:
            piVar10 = (int *)0x0;
            (**(code **)(puStack_558 + -0x7380))(piStack_6a8);
            pcVar33 = *(code **)(puStack_558 + -0x7f58);
          }
          else {
            piStack_54c = piStack_57c + 2;
            iStack_560 = uStack_650 - 8;
            piVar10 = (int *)((int)pcStack_5fc + 8);
            piVar9 = piVar10;
            iStack_548 = iStack_560;
            iVar6 = (**(code **)(puStack_558 + -0x7384))
                              (piStack_6a8,piVar10,ppiStack_5f4,piStack_54c);
            if (iVar6 == 0) goto LAB_0057603c;
            piVar9 = (int *)((int)piVar10 + (int)apiStack_53c[0]);
            iVar6 = (**(code **)(puStack_558 + -0x7388))(piStack_6a8,piVar9,ppiStack_5f4);
            if (iVar6 == 0) goto LAB_0057603c;
            uVar13 = (uint)*(byte *)((int)pcStack_5fc + 9) << 8 |
                     (uint)*(byte *)((int)pcStack_5fc + 10) << 0x10 |
                     (uint)*(byte *)((int)pcStack_5fc + 8) |
                     (uint)*(byte *)((int)pcStack_5fc + 0xb) << 0x18;
            if ((uVar13 != 0x32415352) && (piStack_544 = (int *)0x32535344, uVar13 != 0x32535344)) {
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
              piVar9 = (int *)(**(code **)(puStack_558 + -0x69b8))();
              iStack_560 = 0;
              iVar6 = (**(code **)(puStack_558 + -0x738c))(piStack_6a8,piVar9,0,unaff_s8);
              if (iVar6 != 0) {
                (**(code **)(puStack_558 + -0x7d6c))(unaff_s8,0x14);
                iStack_560 = iStack_548;
                piVar9 = piVar10;
                iVar6 = (**(code **)(puStack_558 + -0x7384))
                                  (piStack_6a8,piVar10,ppiStack_5f4,piStack_54c);
                if (iVar6 != 0) {
                  piStack_54c = piStack_544;
                  piVar9 = (int *)((int)piVar10 + (int)apiStack_53c[0]);
                  iVar6 = (**(code **)(puStack_558 + -0x7388))(piStack_6a8,piVar9,ppiStack_5f4);
                  if (iVar6 != 0) {
                    piVar9 = (int *)((uint)*(byte *)((int)pcStack_5fc + 9) << 8 |
                                     (uint)*(byte *)((int)pcStack_5fc + 10) << 0x10 |
                                     (uint)*(byte *)((int)pcStack_5fc + 8) |
                                    (uint)*(byte *)((int)pcStack_5fc + 0xb) << 0x18);
                    if ((piVar9 == (int *)0x32415352) || (piVar9 == piStack_54c)) goto LAB_0057606c;
                    piVar9 = (int *)0x87;
                    iStack_560 = 0x313;
                    (**(code **)(puStack_558 + -0x6eb0))(9,0x87,0x65,FUN_0066ce6c);
                  }
                }
              }
              goto LAB_0057603c;
            }
            (**(code **)(puStack_558 + -0x7d6c))(unaff_s8,0x14);
LAB_0057606c:
            apiStack_53c[0] = (int *)pcStack_5fc;
            if (uStack_650 < 0x10) {
LAB_0057615c:
              piVar9 = (int *)&DAT_00000084;
              iStack_560 = 0xff;
              piVar10 = (int *)0x0;
              (**(code **)(puStack_558 + -0x6eb0))(9,0x84,0x7a,FUN_0066ce6c);
            }
            else {
              if (*pcStack_5fc == (code)0x6) {
                pcVar33 = *(code **)(puStack_558 + -0x6eb0);
                uVar24 = 0x77;
                iStack_560 = 0x98;
LAB_0057621c:
                apiStack_53c[0] = (int *)pcStack_5fc;
                (*pcVar33)(9,0x86,uVar24,FUN_0066ce6c);
                goto LAB_0057615c;
              }
              if (*pcStack_5fc != (code)0x7) goto LAB_0057615c;
              if (*(char *)((int)pcStack_5fc + 1) != '\x02') {
                pcVar33 = *(code **)(puStack_558 + -0x6eb0);
                uVar24 = 0x75;
                iStack_560 = 0xad;
                goto LAB_0057621c;
              }
              apiStack_53c[0] = (int *)((int)pcStack_5fc + 0x10);
              uVar13 = (uint)*(byte *)((int)pcStack_5fc + 9) << 8 |
                       (uint)*(byte *)((int)pcStack_5fc + 10) << 0x10 |
                       (uint)*(byte *)((int)pcStack_5fc + 8) |
                       (uint)*(byte *)((int)pcStack_5fc + 0xb) << 0x18;
              piVar9 = (int *)((uint)*(byte *)((int)pcStack_5fc + 0xd) << 8 |
                               (uint)*(byte *)((int)pcStack_5fc + 0xe) << 0x10 |
                               (uint)*(byte *)((int)pcStack_5fc + 0xc) |
                              (uint)*(byte *)((int)pcStack_5fc + 0xf) << 0x18);
              if (uVar13 == 0x31535344) {
LAB_0057620c:
                pcVar33 = *(code **)(puStack_558 + -0x6eb0);
                uVar24 = 0x77;
                iStack_560 = 0xbe;
                goto LAB_0057621c;
              }
              if (uVar13 < 0x31535345) {
                if (uVar13 != 0x31415352) {
LAB_00576498:
                  pcVar33 = *(code **)(puStack_558 + -0x6eb0);
                  uVar24 = 0x74;
                  iStack_560 = 0xcf;
                  goto LAB_0057621c;
                }
                goto LAB_0057620c;
              }
              if (uVar13 == 0x32415352) {
                uStack_650 = uStack_650 - 0x10;
                if (uStack_650 <
                    (((uint)((int)piVar9 + 7) >> 3) + 2) * 2 + ((uint)((int)piVar9 + 0xf) >> 4) * 5)
                {
LAB_005764d8:
                  iStack_560 = 0x105;
                  piVar9 = (int *)&DAT_00000084;
                  piVar10 = (int *)0x0;
                  (**(code **)(puStack_558 + -0x6eb0))(9,0x84,0x7b,FUN_0066ce6c);
                }
                else {
                  piVar10 = (int *)b2i_rsa_isra_1(apiStack_53c,piVar9,0);
                }
              }
              else {
                uStack_650 = uStack_650 - 0x10;
                if (uVar13 != 0x32535344) goto LAB_00576498;
                uStack_650 = (uint)(uStack_650 < (((uint)((int)piVar9 + 7) >> 3) + 0x20) * 2);
                if (uStack_650 != 0) goto LAB_005764d8;
                piVar10 = (int *)b2i_dss_isra_0(apiStack_53c,piVar9,0);
              }
            }
            (**(code **)(puStack_558 + -0x7380))(piStack_6a8);
            piStack_57c = piVar10;
            pcStack_5fc = (code *)piVar30;
            if ((piVar30 == (int *)0x0) ||
               (pcVar33 = *(code **)(puStack_558 + -0x7f58), iStack_6a4 == 0)) goto LAB_005761a4;
          }
          (*pcVar33)(piVar30);
          piStack_57c = piVar10;
          pcStack_5fc = (code *)piVar30;
          goto LAB_005761a4;
        }
      }
      (**(code **)(puStack_558 + -0x7fac))(ppiStack_5f4);
      piVar10 = (int *)0x0;
    }
  }
LAB_005761a4:
  piVar30 = (int *)0x670000;
  if (ppcStack_84 == *(char ***)pcVar29) {
    return piVar10;
  }
  pcStack_574 = b2i_PrivateKey;
  ppcVar20 = ppcStack_84;
  (**(code **)(puStack_558 + -0x5328))();
  puStack_5b4 = PTR___stack_chk_guard_006aabf0;
  pcVar11 = *ppcVar20;
  puStack_590 = &_gp;
  ppcStack_584 = *(char ***)PTR___stack_chk_guard_006aabf0;
  pcStack_588 = pcVar11;
  piStack_578 = (int *)pcStack_5fc;
  if (piVar9 < &SUB_00000010) {
LAB_0057659c:
    pcStack_5fc = (code *)0x670000;
    uVar21 = 0x84;
    uStack_598 = 0xff;
    (**(code **)(puStack_590 + -0x6eb0))(9,0x84,0x7a,FUN_0066ce6c);
    piVar9 = (int *)0x0;
  }
  else {
    if (*pcVar11 == '\x06') {
      uVar24 = 0x77;
      uStack_598 = 0x98;
LAB_005766bc:
      pcStack_588 = pcVar11;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x86,uVar24,FUN_0066ce6c);
      goto LAB_0057659c;
    }
    if (*pcVar11 != '\a') goto LAB_0057659c;
    if (pcVar11[1] != '\x02') {
      uVar24 = 0x75;
      uStack_598 = 0xad;
      goto LAB_005766bc;
    }
    pcStack_588 = pcVar11 + 0x10;
    uVar13 = (uint)(byte)pcVar11[9] << 8 | (uint)(byte)pcVar11[10] << 0x10 | (uint)(byte)pcVar11[8]
             | (uint)(byte)pcVar11[0xb] << 0x18;
    uVar21 = (uint)(byte)pcVar11[0xd] << 8 | (uint)(byte)pcVar11[0xe] << 0x10 |
             (uint)(byte)pcVar11[0xc] | (uint)(byte)pcVar11[0xf] << 0x18;
    if (uVar13 == 0x31535344) {
LAB_00576730:
      uVar24 = 0x77;
      uStack_598 = 0xbe;
      goto LAB_005766bc;
    }
    if (uVar13 < 0x31535345) {
      if (uVar13 != 0x31415352) {
LAB_00576760:
        uVar24 = 0x74;
        uStack_598 = 0xcf;
        goto LAB_005766bc;
      }
      goto LAB_00576730;
    }
    if (uVar13 == 0x32415352) {
      if (piVar9 + -4 < (int *)(((uVar21 + 7 >> 3) + 2) * 2 + (uVar21 + 0xf >> 4) * 5)) {
LAB_00576778:
        uStack_598 = 0x105;
        uVar21 = 0x84;
        (*(code *)PTR_ERR_put_error_006a9030)(9,0x84,0x7b,FUN_0066ce6c);
        piVar9 = (int *)0x0;
      }
      else {
        piVar9 = (int *)b2i_rsa_isra_1(&pcStack_588,uVar21,0);
      }
    }
    else {
      if (uVar13 != 0x32535344) goto LAB_00576760;
      if (piVar9 + -4 < (int *)(((uVar21 + 7 >> 3) + 0x20) * 2)) goto LAB_00576778;
      piVar9 = (int *)b2i_dss_isra_0(&pcStack_588,uVar21,0);
    }
  }
  if (ppcStack_584 == *(char ***)puStack_5b4) {
    return piVar9;
  }
  pcStack_5ac = b2i_PublicKey;
  ppcVar20 = ppcStack_584;
  (**(code **)(puStack_590 + -0x5328))();
  puStack_600 = PTR___stack_chk_guard_006aabf0;
  pcVar11 = *ppcVar20;
  puStack_5c8 = &_gp;
  iStack_5bc = *(int *)PTR___stack_chk_guard_006aabf0;
  pcStack_5c0 = pcVar11;
  piStack_5b0 = (int *)pcStack_5fc;
  if (uVar21 < 0x10) {
LAB_0057680c:
    pcStack_5fc = (code *)0x670000;
    uStack_5d0 = 0xff;
    (**(code **)(puStack_5c8 + -0x6eb0))(9,0x84,0x7a,FUN_0066ce6c);
    piVar9 = (int *)0x0;
  }
  else {
    if (*pcVar11 != '\x06') {
      if (*pcVar11 == '\a') {
        uVar24 = 0x78;
        uStack_5d0 = 0xa2;
        goto LAB_00576914;
      }
      goto LAB_0057680c;
    }
    if (pcVar11[1] != '\x02') {
      uVar24 = 0x75;
      uStack_5d0 = 0xad;
LAB_00576914:
      pcStack_5c0 = pcVar11;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x86,uVar24,FUN_0066ce6c);
      goto LAB_0057680c;
    }
    pcStack_5c0 = pcVar11 + 0x10;
    uVar13 = (uint)(byte)pcVar11[9] << 8 | (uint)(byte)pcVar11[10] << 0x10 | (uint)(byte)pcVar11[8]
             | (uint)(byte)pcVar11[0xb] << 0x18;
    uVar23 = (uint)(byte)pcVar11[0xd] << 8 | (uint)(byte)pcVar11[0xe] << 0x10 |
             (uint)(byte)pcVar11[0xc] | (uint)(byte)pcVar11[0xf] << 0x18;
    if (uVar13 != 0x31535344) {
      if (uVar13 < 0x31535345) {
        if (uVar13 == 0x31415352) {
          if (uVar21 - 0x10 < (uVar23 + 7 >> 3) + 4) goto LAB_005769d4;
          piVar9 = (int *)b2i_rsa_isra_1(&pcStack_5c0,uVar23,1);
          goto LAB_00576834;
        }
      }
      else if ((uVar13 == 0x32415352) || (uVar13 == 0x32535344)) {
        uVar24 = 0x78;
        uStack_5d0 = 0xc9;
        goto LAB_00576914;
      }
      uVar24 = 0x74;
      uStack_5d0 = 0xcf;
      goto LAB_00576914;
    }
    if (uVar21 - 0x10 < (uVar23 + 7 >> 3) * 3 + 0x2c) {
LAB_005769d4:
      uStack_5d0 = 0x105;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x84,0x7b,FUN_0066ce6c);
      piVar9 = (int *)0x0;
    }
    else {
      piVar9 = (int *)b2i_dss_isra_0(&pcStack_5c0,uVar23,1);
    }
  }
LAB_00576834:
  if (iStack_5bc == *(int *)puStack_600) {
    return piVar9;
  }
  pcStack_5e4 = b2i_PrivateKey_bio;
  iStack_64c = iStack_5bc;
  (**(code **)(puStack_5c8 + -0x5328))();
  piVar9 = (int *)PTR___stack_chk_guard_006aabf0;
  piStack_658 = (int *)&cStack_614;
  puStack_620 = &_gp;
  puStack_5e8 = pcVar29;
  iStack_604 = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_5f8 = uStack_650;
  piStack_5f0 = piStack_6a8;
  iStack_5ec = iStack_6a4;
  iVar6 = (*(code *)PTR_BIO_read_006a85bc)();
  if (iVar6 == 0x10) {
    piStack_618 = piStack_658;
    if (cStack_614 == '\x06') {
      pcVar33 = *(code **)(puStack_620 + -0x6eb0);
      uVar24 = 0x77;
      uStack_628 = 0x98;
LAB_00576c0c:
      (*pcVar33)(9,0x86,uVar24,FUN_0066ce6c);
    }
    else if (cStack_614 == '\a') {
      if (cStack_613 == '\x02') {
        uVar13 = (((uStack_60c >> 0x10) << 0x18 | (uStack_60c >> 0x18) << 0x10) >> 0x10) +
                 ((uStack_60c & 0xff) << 8 | uStack_60c >> 8 & 0xff) * 0x10000;
        uStack_650 = (((uStack_608 >> 0x10) << 0x18 | (uStack_608 >> 0x18) << 0x10) >> 0x10) +
                     ((uStack_608 & 0xff) << 8 | uStack_608 >> 8 & 0xff) * 0x10000;
        if (uVar13 != 0x31535344) {
          if (0x31535344 < uVar13) {
            if (uVar13 == 0x32415352) {
              iStack_6a4 = 0;
              piStack_658 = (int *)(((uStack_650 + 7 >> 3) + 2) * 2 + (uStack_650 + 0xf >> 4) * 5);
            }
            else {
              iStack_6a4 = 1;
              if (uVar13 != 0x32535344) goto LAB_00576cd8;
              piStack_658 = (int *)(((uStack_650 + 7 >> 3) + 0x20) * 2);
            }
            piStack_618 = &iStack_604;
            pcVar29 = "7 datafinal";
            piStack_6a8 = (int *)(**(code **)(puStack_620 + -0x7dd8))
                                           (piStack_658,FUN_0066ce6c,0x11f);
            if (piStack_6a8 == (int *)0x0) {
              uStack_628 = 0x122;
              (**(code **)(puStack_620 + -0x6eb0))(9,0x85,0x41,FUN_0066ce6c);
              piVar10 = (int *)0x0;
            }
            else {
              piStack_618 = piStack_6a8;
              piVar10 = (int *)(**(code **)(puStack_620 + -0x7924))
                                         (iStack_64c,piStack_6a8,piStack_658);
              if (piStack_658 == piVar10) {
                if (iStack_6a4 == 0) {
                  piVar10 = (int *)b2i_rsa_isra_1(&piStack_618,uStack_650,0);
                }
                else {
                  piVar10 = (int *)b2i_dss_isra_0();
                }
              }
              else {
                uStack_628 = 0x128;
                piVar10 = (int *)0x0;
                (**(code **)(puStack_620 + -0x6eb0))(9,0x85,0x7b,FUN_0066ce6c);
              }
              (**(code **)(puStack_620 + -0x7f58))(piStack_6a8);
              piStack_658 = piVar10;
            }
            goto LAB_00576a94;
          }
          if (uVar13 != 0x31415352) {
LAB_00576cd8:
            pcVar33 = *(code **)(puStack_620 + -0x6eb0);
            uVar24 = 0x74;
            uStack_628 = 0xcf;
            goto LAB_00576c0c;
          }
        }
        pcVar33 = *(code **)(puStack_620 + -0x6eb0);
        uVar24 = 0x77;
        uStack_628 = 0xbe;
      }
      else {
        pcVar33 = *(code **)(puStack_620 + -0x6eb0);
        uVar24 = 0x75;
        uStack_628 = 0xad;
      }
      goto LAB_00576c0c;
    }
    piVar10 = (int *)0x0;
  }
  else {
    uStack_628 = 0x117;
    (**(code **)(puStack_620 + -0x6eb0))(9,0x85,0x7b,FUN_0066ce6c);
    piVar10 = (int *)0x0;
  }
LAB_00576a94:
  if (iStack_604 == *piVar9) {
    return piVar10;
  }
  pcStack_63c = b2i_PublicKey_bio;
  iStack_6ac = iStack_604;
  (**(code **)(puStack_620 + -0x5328))();
  pcVar11 = PTR___stack_chk_guard_006aabf0;
  piVar22 = (int *)&SUB_00000010;
  piVar14 = (int *)&cStack_66c;
  puStack_678 = &_gp;
  puStack_654 = (undefined *)piVar9;
  iStack_65c = *(int *)PTR___stack_chk_guard_006aabf0;
  piVar10 = piVar14;
  piStack_648 = piStack_6a8;
  iStack_644 = iStack_6a4;
  pcStack_640 = pcVar29;
  iVar6 = (*(code *)PTR_BIO_read_006a85bc)();
  if (iVar6 == 0x10) {
    piStack_670 = piVar14;
    if (cStack_66c == '\x06') {
      if (cStack_66b == '\x02') {
        uVar13 = (((uStack_664 >> 0x10) << 0x18 | (uStack_664 >> 0x18) << 0x10) >> 0x10) +
                 ((uStack_664 & 0xff) << 8 | uStack_664 >> 8 & 0xff) * 0x10000;
        piStack_6a8 = (int *)((((uStack_660 >> 0x10) << 0x18 | (uStack_660 >> 0x18) << 0x10) >> 0x10
                              ) + ((uStack_660 & 0xff) << 8 | uStack_660 >> 8 & 0xff) * 0x10000);
        if (uVar13 == 0x31535344) {
          iStack_6a4 = 1;
          piVar14 = (int *)(((uint)((int)piStack_6a8 + 7) >> 3) * 3 + 0x2c);
LAB_00576e9c:
          piStack_670 = &iStack_65c;
          pcVar29 = "7 datafinal";
          piVar9 = (int *)(**(code **)(puStack_678 + -0x7dd8))(piVar14,FUN_0066ce6c,0x11f);
          if (piVar9 == (int *)0x0) {
            piVar22 = (int *)&DAT_00000041;
            piVar10 = (int *)0x85;
            uStack_680 = 0x122;
            (**(code **)(puStack_678 + -0x6eb0))(9,0x85,0x41,FUN_0066ce6c);
            piVar12 = (int *)0x0;
          }
          else {
            piStack_670 = piVar9;
            piVar10 = (int *)(**(code **)(puStack_678 + -0x7924))(iStack_6ac,piVar9,piVar14);
            if (piVar14 == piVar10) {
              piVar22 = (int *)0x1;
              piVar10 = piStack_6a8;
              if (iStack_6a4 == 0) {
                piVar12 = (int *)b2i_rsa_isra_1(&piStack_670);
              }
              else {
                piVar12 = (int *)b2i_dss_isra_0();
              }
            }
            else {
              piVar22 = (int *)0x7b;
              piVar10 = (int *)0x85;
              uStack_680 = 0x128;
              piVar12 = (int *)0x0;
              (**(code **)(puStack_678 + -0x6eb0))(9,0x85,0x7b,FUN_0066ce6c);
            }
            (**(code **)(puStack_678 + -0x7f58))(piVar9);
            piVar14 = piVar12;
          }
          goto LAB_00576d94;
        }
        if (uVar13 < 0x31535345) {
          iStack_6a4 = 0;
          if (uVar13 == 0x31415352) {
            piVar14 = (int *)(((uint)((int)piStack_6a8 + 7) >> 3) + 4);
            goto LAB_00576e9c;
          }
        }
        else if ((uVar13 == 0x32415352) || (uVar13 == 0x32535344)) {
          pcVar33 = *(code **)(puStack_678 + -0x6eb0);
          piVar22 = (int *)&DAT_00000078;
          uStack_680 = 0xc9;
          goto LAB_00576e34;
        }
        pcVar33 = *(code **)(puStack_678 + -0x6eb0);
        piVar22 = (int *)&DAT_00000074;
        uStack_680 = 0xcf;
      }
      else {
        pcVar33 = *(code **)(puStack_678 + -0x6eb0);
        piVar22 = (int *)0x75;
        uStack_680 = 0xad;
      }
LAB_00576e34:
      piVar10 = (int *)0x86;
      (*pcVar33)(9,0x86,piVar22,FUN_0066ce6c);
    }
    else if (cStack_66c == '\a') {
      pcVar33 = *(code **)(puStack_678 + -0x6eb0);
      piVar22 = (int *)&DAT_00000078;
      uStack_680 = 0xa2;
      goto LAB_00576e34;
    }
    piVar12 = (int *)0x0;
  }
  else {
    piVar22 = (int *)0x7b;
    uStack_680 = 0x117;
    piVar10 = (int *)0x85;
    (**(code **)(puStack_678 + -0x6eb0))(9,0x85,0x7b,FUN_0066ce6c);
    piVar12 = (int *)0x0;
  }
LAB_00576d94:
  if (iStack_65c == *(int *)pcVar11) {
    return piVar12;
  }
  pcStack_694 = i2b_PrivateKey_bio;
  iVar6 = iStack_65c;
  (**(code **)(puStack_678 + -0x5328))();
  puVar5 = PTR___stack_chk_guard_006aabf0;
  pcStack_69c = "7 datafinal";
  puStack_6b0 = pcVar11;
  iStack_6c0 = 0;
  iStack_6bc = *(int *)PTR___stack_chk_guard_006aabf0;
  piStack_6b8 = piVar14;
  piStack_6b4 = piVar9;
  pcStack_6a0 = pcVar29;
  piStack_698 = unaff_s8;
  if (*piVar10 == 0x74) {
    piVar14 = (int *)piVar10[5];
    pcVar11 = (char *)(*(code *)PTR_BN_num_bits_006a82f4)(piVar14[3]);
    if ((((((uint)pcVar11 & 7) != 0) ||
         (iVar27 = (*(code *)PTR_BN_num_bits_006a82f4)(piVar14[4]), iVar27 != 0xa0)) ||
        (iVar27 = (*(code *)PTR_BN_num_bits_006a82f4)(piVar14[5]), (int)pcVar11 < iVar27)) ||
       (iVar27 = (*(code *)PTR_BN_num_bits_006a82f4)(piVar14[7]), 0xa0 < iVar27)) {
      piVar22 = (int *)0x7e;
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x82,0x7e,FUN_0066ce6c,0x23c);
      goto LAB_0057782c;
    }
    iStack_6c0 = 0x32535344;
    if (pcVar11 == (char *)0x0) goto LAB_0057782c;
    piVar30 = (int *)0x22;
    pcVar29 = (char *)0x2200;
    iVar27 = (((uint)(pcVar11 + 7) >> 3) + 0x20) * 2;
  }
  else {
    piVar12 = (int *)0xffffffff;
    if (*piVar10 != 6) goto LAB_00577790;
    piVar22 = &iStack_6c0;
    pcVar11 = (char *)check_bitlen_rsa(piVar10[5],0);
    if (pcVar11 == (char *)0x0) goto LAB_0057782c;
    piVar30 = (int *)&DAT_000000a4;
    iVar27 = (((uint)(pcVar11 + 7) >> 3) + 2) * 2 + ((uint)(pcVar11 + 0xf) >> 4) * 5;
    pcVar29 = (char *)0xa400;
  }
  piVar12 = (int *)(iVar27 + 0x10);
  piVar22 = (int *)0x1ff;
  piVar14 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(piVar12,FUN_0066ce6c);
  piVar9 = piVar12;
  if (piVar14 == (int *)0x0) goto LAB_0057782c;
  *(char *)((int)piVar14 + 2) = '\0';
  *(char *)((int)piVar14 + 3) = '\0';
  *(char *)(piVar14 + 1) = '\0';
  *(char *)((int)piVar14 + 5) = (char)piVar30;
  *(char *)((int)piVar14 + 6) = '\0';
  *(char *)piVar14 = '\a';
  piVar30 = piVar14 + 4;
  *(char *)((int)piVar14 + 7) = '\0';
  *(char *)(piVar14 + 3) = (char)pcVar11;
  *(char *)((int)piVar14 + 1) = '\x02';
  *(char *)((int)piVar14 + 0xd) = (char)((uint)pcVar11 >> 8);
  *(char *)((int)piVar14 + 0xe) = (char)((uint)pcVar11 >> 0x10);
  *(char *)((int)piVar14 + 0xf) = (char)((uint)pcVar11 >> 0x18);
  *(char *)(piVar14 + 2) = (char)iStack_6c0;
  *(char *)((int)piVar14 + 9) = (char)((uint)iStack_6c0 >> 8);
  *(char *)((int)piVar14 + 10) = (char)((uint)iStack_6c0 >> 0x10);
  *(char *)((int)piVar14 + 0xb) = (char)((uint)iStack_6c0 >> 0x18);
  if (pcVar29 == (char *)0x2200) {
    iVar25 = piVar10[5];
    iVar15 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(iVar25 + 0xc));
    uVar24 = *(undefined4 *)(iVar25 + 0xc);
    iVar27 = iVar15 + 7;
    if (iVar15 + 7 < 0) {
      iVar27 = iVar15 + 0xe;
    }
    iVar27 = iVar27 >> 3;
    iVar18 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar24);
    iVar26 = iVar18 + 7;
    iVar15 = iVar18 + 0xe;
    if (-1 < iVar26) {
      iVar15 = iVar26;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar24,piVar30);
    iVar15 = iVar15 >> 3;
    iVar18 = iVar18 + 0x16;
    if (-1 < iVar26) {
      iVar18 = iVar26;
    }
    if (0 < iVar18 >> 4) {
      piVar9 = piVar30;
      pcVar29 = (char *)((int)piVar30 + iVar15 + -1);
      do {
        cVar4 = *(char *)piVar9;
        piVar10 = (int *)((int)piVar9 + 1);
        *(char *)piVar9 = *pcVar29;
        *pcVar29 = cVar4;
        piVar9 = piVar10;
        pcVar29 = pcVar29 + -1;
      } while ((int *)((int)piVar30 + (iVar18 >> 4)) != piVar10);
    }
    pcVar11 = (char *)((int)piVar30 + iVar15);
    pcVar29 = pcVar11;
    if ((0 < iVar27) && (0 < iVar27 - iVar15)) {
      pcVar29 = pcVar11 + (iVar27 - iVar15);
      (*(code *)PTR_memset_006aab00)(pcVar11,0);
    }
    uVar24 = *(undefined4 *)(iVar25 + 0x10);
    iVar18 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar24);
    iVar26 = iVar18 + 7;
    iVar15 = iVar18 + 0xe;
    if (-1 < iVar26) {
      iVar15 = iVar26;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar24,pcVar29);
    iVar15 = iVar15 >> 3;
    iVar18 = iVar18 + 0x16;
    if (-1 < iVar26) {
      iVar18 = iVar26;
    }
    if (0 < iVar18 >> 4) {
      pcVar11 = pcVar29;
      pcVar32 = pcVar29 + iVar15 + -1;
      do {
        cVar4 = *pcVar11;
        pcVar31 = pcVar11 + 1;
        *pcVar11 = *pcVar32;
        *pcVar32 = cVar4;
        pcVar11 = pcVar31;
        pcVar32 = pcVar32 + -1;
      } while (pcVar29 + (iVar18 >> 4) != pcVar31);
    }
    pcVar29 = pcVar29 + iVar15;
    pcVar11 = pcVar29;
    if (0 < 0x14 - iVar15) {
      pcVar11 = pcVar29 + (0x14 - iVar15);
      (*(code *)PTR_memset_006aab00)(pcVar29,0);
    }
    uVar24 = *(undefined4 *)(iVar25 + 0x14);
    iVar26 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar24);
    iVar18 = iVar26 + 7;
    iVar15 = iVar26 + 0xe;
    if (-1 < iVar18) {
      iVar15 = iVar18;
    }
    iVar15 = iVar15 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar24,pcVar11);
    if (-1 >= iVar18) {
      iVar18 = iVar26 + 0x16;
    }
    if (0 < iVar18 >> 4) {
      pcVar29 = pcVar11;
      pcVar32 = pcVar11 + iVar15 + -1;
      do {
        cVar4 = *pcVar29;
        pcVar31 = pcVar29 + 1;
        *pcVar29 = *pcVar32;
        *pcVar32 = cVar4;
        pcVar29 = pcVar31;
        pcVar32 = pcVar32 + -1;
      } while (pcVar31 != pcVar11 + (iVar18 >> 4));
    }
    piVar9 = (int *)(pcVar11 + iVar15);
    piVar30 = piVar9;
    if ((0 < iVar27) && (0 < iVar27 - iVar15)) {
      piVar30 = (int *)((int)piVar9 + (iVar27 - iVar15));
      (*(code *)PTR_memset_006aab00)(piVar9,0);
    }
    uVar24 = *(undefined4 *)(iVar25 + 0x1c);
    iVar27 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar24);
    pcVar11 = (char *)(iVar27 + 7);
    pcVar32 = (char *)(iVar27 + 0xe);
    if (-1 < (int)pcVar11) {
      pcVar32 = pcVar11;
    }
    pcVar29 = (char *)(iVar27 + 0x16);
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar24,piVar30);
    if (-1 >= (int)pcVar11) {
      pcVar11 = pcVar29;
    }
    piVar10 = (int *)((int)pcVar32 >> 3);
    if (0 < (int)pcVar11 >> 4) {
      piVar9 = piVar30;
      pcVar32 = (char *)((int)piVar30 + (int)((int)piVar10 + -1));
      do {
        cVar4 = *(char *)piVar9;
        piVar22 = (int *)((int)piVar9 + 1);
        *(char *)piVar9 = *pcVar32;
        *pcVar32 = cVar4;
        piVar9 = piVar22;
        pcVar32 = pcVar32 + -1;
      } while (piVar22 != (int *)((int)piVar30 + ((int)pcVar11 >> 4)));
    }
    pcVar32 = (char *)((int)piVar30 + (int)piVar10);
    pcVar11 = pcVar32;
    if (0 < 0x14 - (int)piVar10) {
      pcVar11 = pcVar32 + (0x14 - (int)piVar10);
      (*(code *)PTR_memset_006aab00)(pcVar32,0);
    }
    piVar22 = (int *)&DAT_00000018;
    (*(code *)PTR_memset_006aab00)(pcVar11,0xff);
    piVar19 = piVar14;
    goto LAB_00577758;
  }
  pcVar29 = (char *)piVar10[5];
  iVar15 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(pcVar29 + 0x10));
  iVar27 = iVar15 + 7;
  if (iVar15 + 7 < 0) {
    iVar27 = iVar15 + 0xe;
  }
  piVar10 = (int *)(iVar27 >> 3);
  iVar27 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(pcVar29 + 0x10));
  uVar24 = *(undefined4 *)(pcVar29 + 0x14);
  pcVar11 = (char *)(iVar27 + 0xf >> 4);
  iVar15 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar24);
  iVar25 = iVar15 + 7;
  iVar27 = iVar15 + 0xe;
  if (-1 < iVar25) {
    iVar27 = iVar25;
  }
  iVar27 = iVar27 >> 3;
  (*(code *)PTR_BN_bn2bin_006a8300)(uVar24,piVar30);
  iVar15 = iVar15 + 0x16;
  if (-1 < iVar25) {
    iVar15 = iVar25;
  }
  if (0 < iVar15 >> 4) {
    piVar9 = piVar30;
    pcVar32 = (char *)((int)piVar30 + iVar27 + -1);
    do {
      cVar4 = *(char *)piVar9;
      piVar22 = (int *)((int)piVar9 + 1);
      *(char *)piVar9 = *pcVar32;
      *pcVar32 = cVar4;
      piVar9 = piVar22;
      pcVar32 = pcVar32 + -1;
    } while ((int *)((int)piVar30 + (iVar15 >> 4)) != piVar22);
  }
  pcVar31 = (char *)((int)piVar30 + iVar27);
  pcVar32 = pcVar31;
  if (0 < 4 - iVar27) {
    pcVar32 = pcVar31 + (4 - iVar27);
    (*(code *)PTR_memset_006aab00)(pcVar31,0);
  }
  uVar24 = *(undefined4 *)(pcVar29 + 0x10);
  iVar25 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar24);
  iVar15 = iVar25 + 7;
  (*(code *)PTR_BN_bn2bin_006a8300)(uVar24,pcVar32);
  iVar27 = iVar15;
  if (iVar15 < 0) {
    iVar15 = iVar25 + 0x16;
    iVar27 = iVar25 + 0xe;
  }
  if (0 < iVar15 >> 4) {
    pcVar31 = pcVar32;
    pcVar17 = pcVar32 + (iVar27 >> 3) + -1;
    do {
      cVar4 = *pcVar31;
      pcVar16 = pcVar31 + 1;
      *pcVar31 = *pcVar17;
      *pcVar17 = cVar4;
      pcVar31 = pcVar16;
      pcVar17 = pcVar17 + -1;
    } while (pcVar16 != pcVar32 + (iVar15 >> 4));
  }
  uVar24 = *(undefined4 *)(pcVar29 + 0x1c);
  pcVar32 = pcVar32 + (iVar27 >> 3);
  iVar15 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar24);
  iVar25 = iVar15 + 7;
  iVar27 = iVar15 + 0xe;
  if (-1 < iVar25) {
    iVar27 = iVar25;
  }
  iVar27 = iVar27 >> 3;
  (*(code *)PTR_BN_bn2bin_006a8300)(uVar24,pcVar32);
  iVar15 = iVar15 + 0x16;
  if (-1 < iVar25) {
    iVar15 = iVar25;
  }
  if (0 < iVar15 >> 4) {
    pcVar31 = pcVar32;
    pcVar17 = pcVar32 + iVar27 + -1;
    do {
      cVar4 = *pcVar31;
      pcVar16 = pcVar31 + 1;
      *pcVar31 = *pcVar17;
      *pcVar17 = cVar4;
      pcVar31 = pcVar16;
      pcVar17 = pcVar17 + -1;
    } while (pcVar32 + (iVar15 >> 4) != pcVar16);
  }
  pcVar32 = pcVar32 + iVar27;
  if ((int)pcVar11 < 1) {
    uVar24 = *(undefined4 *)(pcVar29 + 0x20);
    iVar15 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar24);
    iVar25 = iVar15 + 7;
    iVar27 = iVar15 + 0xe;
    if (-1 < iVar25) {
      iVar27 = iVar25;
    }
    iVar27 = iVar27 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar24,pcVar32);
    iVar15 = iVar15 + 0x16;
    if (-1 < iVar25) {
      iVar15 = iVar25;
    }
    iVar15 = iVar15 >> 4;
    pcVar31 = pcVar32 + iVar27 + -1;
    if (0 < iVar15) goto LAB_0057740c;
    pcVar32 = pcVar32 + iVar27;
LAB_00577bcc:
    uVar24 = *(undefined4 *)(pcVar29 + 0x24);
    iVar15 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar24);
    iVar25 = iVar15 + 7;
    iVar27 = iVar15 + 0xe;
    if (-1 < iVar25) {
      iVar27 = iVar25;
    }
    iVar27 = iVar27 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar24,pcVar32);
    iVar15 = iVar15 + 0x16;
    if (-1 < iVar25) {
      iVar15 = iVar25;
    }
    iVar15 = iVar15 >> 4;
    pcVar31 = pcVar32 + iVar27 + -1;
    if (0 < iVar15) goto LAB_005774d0;
    pcVar32 = pcVar32 + iVar27;
LAB_00577c44:
    uVar24 = *(undefined4 *)(pcVar29 + 0x28);
    iVar25 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar24);
    iVar27 = iVar25 + 7;
    iVar15 = iVar25 + 0xe;
    if (-1 < iVar27) {
      iVar15 = iVar27;
    }
    iVar15 = iVar15 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar24,pcVar32);
    if (-1 >= iVar27) {
      iVar27 = iVar25 + 0x16;
    }
    iVar27 = iVar27 >> 4;
    pcVar31 = pcVar32 + iVar15 + -1;
    if (0 < iVar27) goto LAB_00577594;
LAB_005775b8:
    piVar30 = (int *)(pcVar32 + iVar15);
    if ((int)pcVar11 < 1) {
      uVar24 = *(undefined4 *)(pcVar29 + 0x2c);
      iVar25 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar24);
      iVar15 = iVar25 + 7;
      iVar27 = iVar25 + 0xe;
      if (-1 < iVar15) {
        iVar27 = iVar15;
      }
      piVar22 = (int *)(iVar27 >> 3);
      (*(code *)PTR_BN_bn2bin_006a8300)(uVar24,piVar30);
      if (-1 >= iVar15) {
        iVar15 = iVar25 + 0x16;
      }
      iVar15 = iVar15 >> 4;
      pcVar32 = (char *)((int)piVar30 + (int)((int)piVar22 + -1));
      if (iVar15 < 1) {
        piVar30 = (int *)((int)piVar30 + (int)piVar22);
        goto LAB_005776a4;
      }
      goto LAB_00577658;
    }
  }
  else {
    iVar27 = (int)pcVar11 - iVar27;
    if (0 < iVar27) {
      (*(code *)PTR_memset_006aab00)(pcVar32,0,iVar27);
      pcVar32 = pcVar32 + iVar27;
    }
    uVar24 = *(undefined4 *)(pcVar29 + 0x20);
    iVar15 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar24);
    iVar25 = iVar15 + 7;
    iVar27 = iVar15 + 0xe;
    if (-1 < iVar25) {
      iVar27 = iVar25;
    }
    iVar27 = iVar27 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar24,pcVar32);
    iVar15 = iVar15 + 0x16;
    if (-1 < iVar25) {
      iVar15 = iVar25;
    }
    iVar15 = iVar15 >> 4;
    pcVar31 = pcVar32 + iVar27 + -1;
    if (iVar15 < 1) {
      pcVar32 = pcVar32 + iVar27;
    }
    else {
LAB_0057740c:
      pcVar17 = pcVar32;
      do {
        cVar4 = *pcVar17;
        pcVar16 = pcVar17 + 1;
        *pcVar17 = *pcVar31;
        *pcVar31 = cVar4;
        pcVar17 = pcVar16;
        pcVar31 = pcVar31 + -1;
      } while (pcVar32 + iVar15 != pcVar16);
      pcVar32 = pcVar32 + iVar27;
      if ((int)pcVar11 < 1) goto LAB_00577bcc;
    }
    iVar27 = (int)pcVar11 - iVar27;
    if (0 < iVar27) {
      (*(code *)PTR_memset_006aab00)(pcVar32,0,iVar27);
      pcVar32 = pcVar32 + iVar27;
    }
    uVar24 = *(undefined4 *)(pcVar29 + 0x24);
    iVar15 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar24);
    iVar25 = iVar15 + 7;
    iVar27 = iVar15 + 0xe;
    if (-1 < iVar25) {
      iVar27 = iVar25;
    }
    iVar27 = iVar27 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar24,pcVar32);
    iVar15 = iVar15 + 0x16;
    if (-1 < iVar25) {
      iVar15 = iVar25;
    }
    iVar15 = iVar15 >> 4;
    pcVar31 = pcVar32 + iVar27 + -1;
    if (iVar15 < 1) {
      pcVar32 = pcVar32 + iVar27;
    }
    else {
LAB_005774d0:
      pcVar17 = pcVar32;
      do {
        cVar4 = *pcVar17;
        pcVar16 = pcVar17 + 1;
        *pcVar17 = *pcVar31;
        *pcVar31 = cVar4;
        pcVar17 = pcVar16;
        pcVar31 = pcVar31 + -1;
      } while (pcVar32 + iVar15 != pcVar16);
      pcVar32 = pcVar32 + iVar27;
      if ((int)pcVar11 < 1) goto LAB_00577c44;
    }
    iVar27 = (int)pcVar11 - iVar27;
    if (0 < iVar27) {
      (*(code *)PTR_memset_006aab00)(pcVar32,0,iVar27);
      pcVar32 = pcVar32 + iVar27;
    }
    uVar24 = *(undefined4 *)(pcVar29 + 0x28);
    iVar25 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar24);
    iVar27 = iVar25 + 7;
    iVar15 = iVar25 + 0xe;
    if (-1 < iVar27) {
      iVar15 = iVar27;
    }
    iVar15 = iVar15 >> 3;
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar24,pcVar32);
    if (-1 >= iVar27) {
      iVar27 = iVar25 + 0x16;
    }
    iVar27 = iVar27 >> 4;
    pcVar31 = pcVar32 + iVar15 + -1;
    if (0 < iVar27) {
LAB_00577594:
      pcVar17 = pcVar32;
      do {
        cVar4 = *pcVar17;
        pcVar16 = pcVar17 + 1;
        *pcVar17 = *pcVar31;
        *pcVar31 = cVar4;
        pcVar31 = pcVar31 + -1;
        pcVar17 = pcVar16;
      } while (pcVar32 + iVar27 != pcVar16);
      goto LAB_005775b8;
    }
    piVar30 = (int *)(pcVar32 + iVar15);
  }
  iVar15 = (int)pcVar11 - iVar15;
  if (0 < iVar15) {
    (*(code *)PTR_memset_006aab00)(piVar30,0,iVar15);
    piVar30 = (int *)((int)piVar30 + iVar15);
  }
  uVar24 = *(undefined4 *)(pcVar29 + 0x2c);
  iVar25 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar24);
  iVar15 = iVar25 + 7;
  iVar27 = iVar25 + 0xe;
  if (-1 < iVar15) {
    iVar27 = iVar15;
  }
  piVar22 = (int *)(iVar27 >> 3);
  (*(code *)PTR_BN_bn2bin_006a8300)(uVar24,piVar30);
  if (-1 >= iVar15) {
    iVar15 = iVar25 + 0x16;
  }
  iVar15 = iVar15 >> 4;
  pcVar32 = (char *)((int)piVar30 + (int)((int)piVar22 + -1));
  if (iVar15 < 1) goto LAB_00577dbc;
LAB_00577658:
  piVar9 = piVar30;
  do {
    cVar4 = *(char *)piVar9;
    piVar19 = (int *)((int)piVar9 + 1);
    *(char *)piVar9 = *pcVar32;
    *pcVar32 = cVar4;
    pcVar32 = pcVar32 + -1;
    piVar9 = piVar19;
  } while ((int *)((int)piVar30 + iVar15) != piVar19);
  piVar9 = (int *)((int)piVar30 + (int)piVar22);
  piVar30 = piVar9;
  if ((int)pcVar11 < 1) goto LAB_005776a4;
  do {
    piVar30 = piVar9;
    if (0 < (int)pcVar11 - (int)piVar22) {
      piVar30 = (int *)((int)piVar9 + ((int)pcVar11 - (int)piVar22));
      (*(code *)PTR_memset_006aab00)(piVar9,0);
    }
LAB_005776a4:
    uVar24 = *(undefined4 *)(pcVar29 + 0x18);
    iVar25 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar24);
    iVar27 = iVar25 + 7;
    pcVar11 = (char *)(uint)(iVar27 < 0);
    iVar15 = iVar25 + 0xe;
    if (pcVar11 == (char *)0x0) {
      iVar15 = iVar27;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar24,piVar30);
    pcVar29 = (char *)(iVar15 >> 3);
    if (pcVar11 != (char *)0x0) {
      iVar27 = iVar25 + 0x16;
    }
    piVar22 = (int *)(iVar27 >> 4);
    if (0 < (int)piVar22) {
      piVar22 = (int *)((int)piVar30 + (int)piVar22);
      pcVar32 = (char *)((int)piVar30 + (int)(pcVar29 + -1));
      piVar9 = piVar30;
      do {
        cVar4 = *(char *)piVar9;
        piVar19 = (int *)((int)piVar9 + 1);
        *(char *)piVar9 = *pcVar32;
        *pcVar32 = cVar4;
        pcVar32 = pcVar32 + -1;
        piVar9 = piVar19;
      } while (piVar22 != piVar19);
    }
    piVar19 = piVar14;
    if ((0 < (int)piVar10) && (piVar22 = (int *)((int)piVar10 - (int)pcVar29), 0 < (int)piVar22)) {
      (*(code *)PTR_memset_006aab00)((char *)((int)piVar30 + (int)pcVar29),0);
    }
LAB_00577758:
    piVar14 = piVar19;
    piVar9 = piVar12;
    if ((int)piVar12 < 0) {
LAB_0057782c:
      piVar12 = (int *)0xffffffff;
    }
    else {
      piVar22 = piVar12;
      piVar14 = (int *)(*(code *)PTR_BIO_write_006a7f14)(iVar6,piVar19);
      (*(code *)PTR_CRYPTO_free_006a7f88)(piVar19);
      if (piVar14 != piVar12) goto LAB_0057782c;
    }
LAB_00577790:
    if (iStack_6bc == *(int *)puVar5) {
      return piVar12;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    piVar12 = piVar9;
LAB_00577dbc:
    piVar9 = (int *)((int)piVar30 + (int)piVar22);
  } while( true );
}

