
int gost_imit_update(int param_1,int **param_2,uint param_3)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int **ppiVar11;
  int iVar12;
  int iVar13;
  uint unaff_s1;
  int *piVar14;
  int **unaff_s2;
  int unaff_s3;
  int unaff_s4;
  undefined *puVar15;
  int **unaff_s6;
  int **ppiVar16;
  code *pcVar17;
  int *piStack_bc;
  undefined4 uStack_b8;
  int *piStack_b4;
  int **ppiStack_b0;
  int *piStack_ac;
  int *piStack_a8;
  undefined *puStack_a4;
  int iStack_a0;
  undefined *puStack_9c;
  int **ppiStack_98;
  code *pcStack_94;
  undefined *puStack_80;
  int iStack_78;
  int iStack_74;
  int iStack_70;
  uint uStack_6c;
  int **ppiStack_68;
  int iStack_64;
  int iStack_60;
  code *pcStack_5c;
  undefined *local_48;
  int local_3c;
  undefined auStack_34 [8];
  int *local_2c;
  
  puVar15 = PTR___stack_chk_guard_006aabf0;
  iStack_70 = *(int *)(param_1 + 0xc);
  local_48 = &_gp;
  local_2c = *(int **)PTR___stack_chk_guard_006aabf0;
  if (*(int *)(iStack_70 + 0x103c) == 0) {
    ppiStack_b0 = (int **)&DAT_00000074;
    local_3c = *(int *)(iStack_70 + 0x103c);
    ERR_GOST_error(0x73,0x74,"gost_crypt.c",0x21b);
    iVar10 = local_3c;
  }
  else {
    uVar7 = *(uint *)(iStack_70 + 0x1038);
    unaff_s1 = param_3;
    unaff_s2 = param_2;
    if (uVar7 == 0) {
LAB_0061e3cc:
      unaff_s3 = iStack_70 + 0x1020;
      if (unaff_s1 < 9) {
        ppiStack_b0 = param_2;
        if (unaff_s1 != 0) {
          pcVar17 = *(code **)(local_48 + -0x52ec);
          goto LAB_0061e478;
        }
      }
      else {
        unaff_s4 = 0x400;
        unaff_s6 = unaff_s2;
        uVar7 = unaff_s1;
        do {
          if ((*(int *)(iStack_70 + 0x1034) != 0) && (*(int *)(iStack_70 + 0x1030) == 0x400)) {
            cryptopro_key_meshing(iStack_70,auStack_34,unaff_s6);
          }
          mac_block(iStack_70,unaff_s3,unaff_s6);
          uVar7 = uVar7 - 8;
          unaff_s6 = unaff_s6 + 2;
          *(uint *)(iStack_70 + 0x1030) = (*(uint *)(iStack_70 + 0x1030) & 0x3ff) + 8;
        } while (8 < uVar7);
        uVar7 = unaff_s1 - 9;
        unaff_s1 = (unaff_s1 - 8) - (uVar7 & 0xfffffff8);
        unaff_s2 = unaff_s2 + ((uVar7 >> 3) + 1) * 2;
        pcVar17 = *(code **)(local_48 + -0x52ec);
LAB_0061e478:
        ppiStack_b0 = unaff_s2;
        (*pcVar17)(iStack_70 + 0x1028,unaff_s2,unaff_s1);
      }
      *(uint *)(iStack_70 + 0x1038) = unaff_s1;
      iVar10 = 1;
    }
    else {
      uVar4 = uVar7;
      ppiStack_b0 = param_2;
      if (uVar7 < 8) {
        if (param_3 != 0) {
          uVar4 = uVar7 + 1;
          ppiStack_b0 = (int **)&DAT_00000008;
          unaff_s1 = param_3 - 1;
          *(undefined *)(iStack_70 + uVar7 + 0x1028) = *(undefined *)param_2;
          unaff_s2 = (int **)((int)param_2 + 1);
          if (uVar4 != 8) {
            iVar10 = uVar7 + 2;
            if (unaff_s1 == 0) goto LAB_0061e4dc;
            unaff_s1 = param_3 - 2;
            unaff_s2 = (int **)((int)param_2 + 2);
            *(undefined *)(iStack_70 + uVar4 + 0x1028) = *(undefined *)((int)param_2 + 1);
            if (iVar10 != 8) {
              bVar1 = unaff_s1 == 0;
              unaff_s1 = param_3 - 3;
              if (bVar1) {
LAB_0061e52c:
                *(int *)(iStack_70 + 0x1038) = iVar10;
                iVar10 = 1;
                unaff_s1 = param_3;
                unaff_s2 = param_2;
                goto LAB_0061e494;
              }
              uVar4 = uVar7 + 3;
              unaff_s2 = (int **)((int)param_2 + 3);
              *(undefined *)(iStack_70 + iVar10 + 0x1028) = *(undefined *)((int)param_2 + 2);
              if (uVar4 != 8) {
                iVar10 = uVar7 + 4;
                if (unaff_s1 == 0) goto LAB_0061e4dc;
                unaff_s1 = param_3 - 4;
                *(undefined *)(iStack_70 + uVar4 + 0x1028) = *(undefined *)((int)param_2 + 3);
                unaff_s2 = param_2 + 1;
                if (iVar10 != 8) {
                  bVar1 = unaff_s1 == 0;
                  unaff_s1 = param_3 - 5;
                  if (bVar1) goto LAB_0061e52c;
                  uVar4 = uVar7 + 5;
                  unaff_s2 = (int **)((int)param_2 + 5);
                  *(undefined *)(iStack_70 + iVar10 + 0x1028) = *(undefined *)(param_2 + 1);
                  if (uVar4 != 8) {
                    bVar1 = unaff_s1 == 0;
                    unaff_s1 = param_3 - 6;
                    if (bVar1) goto LAB_0061e4dc;
                    ppiStack_b0 = (int **)0x1;
                    unaff_s2 = (int **)((int)param_2 + 6);
                    *(undefined *)(iStack_70 + uVar4 + 0x1028) = *(undefined *)((int)param_2 + 5);
                    if (uVar7 == 1) {
                      if (unaff_s1 == 0) {
                        *(undefined4 *)(iStack_70 + 0x1038) = 7;
                        iVar10 = 1;
                        unaff_s1 = param_3 - 7;
                        unaff_s2 = param_2;
                        goto LAB_0061e494;
                      }
                      *(undefined *)(iStack_70 + 0x102f) = *(undefined *)((int)param_2 + 6);
                      unaff_s1 = param_3 - 7;
                      unaff_s2 = (int **)((int)param_2 + 7);
                    }
                  }
                }
              }
            }
          }
LAB_0061e370:
          iVar10 = iStack_70 + 0x1028;
          if ((*(int *)(iStack_70 + 0x1034) != 0) && (*(int *)(iStack_70 + 0x1030) == 0x400)) {
            local_3c = iVar10;
            cryptopro_key_meshing(iStack_70,auStack_34);
            iVar10 = local_3c;
          }
          param_2 = (int **)(iStack_70 + 0x1020);
          mac_block(iStack_70,param_2,iVar10);
          *(uint *)(iStack_70 + 0x1030) = (*(uint *)(iStack_70 + 0x1030) & 0x3ff) + 8;
          goto LAB_0061e3cc;
        }
      }
      else if (uVar7 == 8) goto LAB_0061e370;
LAB_0061e4dc:
      *(uint *)(iStack_70 + 0x1038) = uVar4;
      iVar10 = 1;
      unaff_s1 = param_3;
      unaff_s2 = param_2;
    }
  }
LAB_0061e494:
  if (local_2c == *(int **)puVar15) {
    return iVar10;
  }
  pcStack_5c = gost89_get_asn1_parameters;
  piStack_a8 = local_2c;
  (**(code **)(local_48 + -0x5328))();
  puStack_a4 = PTR___stack_chk_guard_006aabf0;
  puStack_80 = &_gp;
  iStack_74 = *(int *)PTR___stack_chk_guard_006aabf0;
  piVar14 = (int *)piStack_a8[0x18];
  ppiVar11 = ppiStack_b0;
  uStack_6c = unaff_s1;
  ppiStack_68 = unaff_s2;
  iStack_64 = unaff_s3;
  iStack_60 = unaff_s4;
  iVar10 = (*(code *)PTR_ASN1_TYPE_get_006a85b0)(ppiStack_b0);
  if (iVar10 != 0x10) {
    iVar10 = -1;
    goto LAB_0061e6b8;
  }
  iStack_78 = ppiStack_b0[1][2];
  ppiStack_b0 = (int **)d2i_GOST_CIPHER_PARAMS(0,&iStack_78,*ppiStack_b0[1]);
  unaff_s4 = **ppiStack_b0;
  if (unaff_s4 != *(int *)(*piStack_a8 + 0xc)) {
    GOST_CIPHER_PARAMS_free(ppiStack_b0);
    ppiVar11 = (int **)&DAT_0000006e;
    ERR_GOST_error(0x6c,0x6e,"gost_crypt.c",0x1e9);
    iVar10 = -1;
    goto LAB_0061e6b8;
  }
  iVar10 = (**(code **)(puStack_80 + -0x7cb4))(ppiStack_b0[1]);
  if ((iVar10 == 0) || (iVar10 = (**(code **)(puStack_80 + -0x7ca0))(iVar10), iVar10 == 0)) {
    pcVar5 = (char *)get_gost_engine_param(0);
    if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\0')) {
      piVar8 = (int *)(gost_cipher_list + 0xc);
      iVar13 = gost_cipher_list._16_4_;
      iVar12 = gost_cipher_list._12_4_;
LAB_0061e660:
      iVar6 = piVar8[2];
      goto LAB_0061e664;
    }
    iVar10 = (**(code **)(puStack_80 + -0x7e84))(pcVar5);
    if (iVar10 != 0) goto LAB_0061e70c;
    ppiVar11 = (int **)&DAT_0000006b;
    ERR_GOST_error(0x67,0x6b,"gost_crypt.c",0x90);
  }
  else {
    iVar10 = (**(code **)(puStack_80 + -0x7cb4))(iVar10);
LAB_0061e70c:
    if (gost_cipher_list._4_4_ != 0) {
      iVar6 = gost_cipher_list._8_4_;
      iVar13 = gost_cipher_list._4_4_;
      iVar12 = gost_cipher_list._0_4_;
      piVar9 = (int *)gost_cipher_list;
      if (iVar10 != gost_cipher_list._0_4_) {
        do {
          piVar8 = piVar9 + 3;
          iVar13 = piVar9[4];
          if (iVar13 == 0) goto LAB_0061e750;
          iVar12 = *piVar8;
          piVar9 = piVar8;
        } while (iVar12 != iVar10);
        goto LAB_0061e660;
      }
LAB_0061e664:
      *piVar14 = iVar12;
      piVar14[1] = 0;
      piVar14[2] = iVar6;
      gost_init(piVar14 + 3,iVar13);
      ppiVar11 = (int **)(*ppiStack_b0)[2];
      (**(code **)(puStack_80 + -0x52ec))(piStack_a8 + 4,ppiVar11,unaff_s4);
      GOST_CIPHER_PARAMS_free(ppiStack_b0);
      iVar10 = 1;
      goto LAB_0061e6b8;
    }
LAB_0061e750:
    ppiVar11 = (int **)&DAT_0000006a;
    ERR_GOST_error(0x67,0x6a,"gost_crypt.c",0x9c);
  }
  GOST_CIPHER_PARAMS_free(ppiStack_b0);
  iVar10 = -1;
LAB_0061e6b8:
  if (iStack_74 == *(int *)puStack_a4) {
    return iVar10;
  }
  pcStack_94 = gost_imit_final;
  iVar10 = iStack_74;
  (**(code **)(puStack_80 + -0x5328))();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iVar13 = *(int *)(iVar10 + 0xc);
  puStack_9c = puVar15;
  piStack_b4 = *(int **)PTR___stack_chk_guard_006aabf0;
  iVar10 = *(int *)(iVar13 + 0x103c);
  ppiVar16 = unaff_s6;
  piStack_ac = piVar14;
  iStack_a0 = unaff_s4;
  ppiStack_98 = unaff_s6;
  if (iVar10 == 0) {
    ERR_GOST_error(0x8c,0x74,"gost_crypt.c",0x240);
    while (piStack_b4 != *(int **)puVar2) {
      (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0061ea0c:
      mac_block(iVar13,iVar13 + 0x1020,puVar15);
      puVar3 = PTR_memcpy_006aabf4;
      *(uint *)(iVar13 + 0x1030) = (*(uint *)(iVar13 + 0x1030) & 0x3ff) + 8;
      (*(code *)puVar3)(puVar15,ppiVar16,piVar14);
      *(int **)(iVar13 + 0x1038) = piVar14;
LAB_0061e8bc:
      if ((int)piVar14 < 8) {
        (*(code *)PTR_memset_006aab00)
                  ((undefined *)((int)piVar14 + iVar13 + 0x1028),0,8 - (int)piVar14);
      }
      if ((*(int *)(iVar13 + 0x1034) != 0) && (*(int *)(iVar13 + 0x1030) == 0x400)) {
        cryptopro_key_meshing(iVar13,&piStack_bc);
      }
      mac_block(iVar13,iVar13 + 0x1020,puVar15);
      *(uint *)(iVar13 + 0x1030) = (*(uint *)(iVar13 + 0x1030) & 0x3ff) + 8;
      unaff_s6 = ppiVar16;
LAB_0061e860:
      get_mac(iVar13 + 0x1020,0x20,ppiVar11);
      iVar10 = 1;
      ppiVar16 = unaff_s6;
    }
    return iVar10;
  }
  piVar14 = *(int **)(iVar13 + 0x1038);
  if (*(int *)(iVar13 + 0x1030) != 0) {
    if (piVar14 == (int *)0x0) goto LAB_0061e860;
    puVar15 = (undefined *)(iVar13 + 0x1028);
    goto LAB_0061e8bc;
  }
  if (piVar14 == (int *)0x0) goto LAB_0061e860;
  ppiVar16 = &piStack_bc;
  piStack_bc = (int *)0x0;
  uStack_b8 = 0;
  if (&DAT_00000008 <= piVar14) {
    puVar15 = (undefined *)(iVar13 + 0x1028);
    if (piVar14 == (int *)&DAT_00000008) goto LAB_0061ea0c;
    *(int **)(iVar13 + 0x1038) = piVar14;
    goto LAB_0061e8bc;
  }
  *(undefined *)((int)piVar14 + iVar13 + 0x1028) = 0;
  if ((undefined *)((int)piVar14 + 1) != (undefined *)0x8) {
    ((undefined *)((int)piVar14 + 1))[iVar13 + 0x1028] = 0;
    if ((undefined *)((int)piVar14 + 2) != (undefined *)0x8) {
      ((undefined *)((int)piVar14 + 2))[iVar13 + 0x1028] = 0;
      if ((undefined *)((int)piVar14 + 3) != (undefined *)0x8) {
        ((undefined *)((int)piVar14 + 3))[iVar13 + 0x1028] = 0;
        if (piVar14 + 1 != (int *)&DAT_00000008) {
          *(undefined *)((int)(piVar14 + 1) + iVar13 + 0x1028) = 0;
          if (((undefined *)((int)piVar14 + 5) != (undefined *)0x8) &&
             (((undefined *)((int)piVar14 + 5))[iVar13 + 0x1028] = 0, piVar14 == (int *)0x1)) {
            *(undefined *)(iVar13 + 0x102f) = 0;
          }
        }
      }
    }
  }
  puVar15 = (undefined *)(iVar13 + 0x1028);
  ppiVar16 = (int **)((int)&piStack_b4 - (int)piVar14);
  goto LAB_0061ea0c;
}

