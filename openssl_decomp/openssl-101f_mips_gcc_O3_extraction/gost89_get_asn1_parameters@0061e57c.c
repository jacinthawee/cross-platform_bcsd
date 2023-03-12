
int gost89_get_asn1_parameters(int *param_1,int **param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int **ppiVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int unaff_s4;
  int unaff_s5;
  undefined4 *unaff_s6;
  undefined4 uStack_64;
  undefined4 uStack_60;
  int iStack_5c;
  int **ppiStack_58;
  int *piStack_54;
  int *piStack_50;
  undefined *puStack_4c;
  int iStack_48;
  int local_20;
  int local_1c;
  
  puStack_4c = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  piVar11 = (int *)param_1[0x18];
  ppiVar8 = param_2;
  iVar3 = (*(code *)PTR_ASN1_TYPE_get_006a85b0)(param_2);
  if (iVar3 != 0x10) {
    iVar3 = -1;
    goto LAB_0061e6b8;
  }
  local_20 = param_2[1][2];
  param_2 = (int **)d2i_GOST_CIPHER_PARAMS(0,&local_20,*param_2[1]);
  unaff_s4 = **param_2;
  if (unaff_s4 != *(int *)(*param_1 + 0xc)) {
    GOST_CIPHER_PARAMS_free(param_2);
    ppiVar8 = (int **)&DAT_0000006e;
    ERR_GOST_error(0x6c,0x6e,"gost_crypt.c",0x1e9);
    iVar3 = -1;
    goto LAB_0061e6b8;
  }
  iVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(param_2[1]);
  if ((iVar3 == 0) || (iVar3 = (*(code *)PTR_OBJ_nid2obj_006a8240)(iVar3), iVar3 == 0)) {
    pcVar4 = (char *)get_gost_engine_param(0);
    if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
      piVar6 = (int *)(gost_cipher_list + 0xc);
      iVar10 = gost_cipher_list._16_4_;
      iVar9 = gost_cipher_list._12_4_;
LAB_0061e660:
      iVar5 = piVar6[2];
      goto LAB_0061e664;
    }
    iVar3 = (*(code *)PTR_OBJ_txt2nid_006a805c)(pcVar4);
    if (iVar3 != 0) goto LAB_0061e70c;
    ppiVar8 = (int **)&DAT_0000006b;
    ERR_GOST_error(0x67,0x6b,"gost_crypt.c",0x90);
  }
  else {
    iVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(iVar3);
LAB_0061e70c:
    if (gost_cipher_list._4_4_ != 0) {
      iVar5 = gost_cipher_list._8_4_;
      iVar10 = gost_cipher_list._4_4_;
      iVar9 = gost_cipher_list._0_4_;
      piVar7 = (int *)gost_cipher_list;
      if (iVar3 != gost_cipher_list._0_4_) {
        do {
          piVar6 = piVar7 + 3;
          iVar10 = piVar7[4];
          if (iVar10 == 0) goto LAB_0061e750;
          iVar9 = *piVar6;
          piVar7 = piVar6;
        } while (iVar9 != iVar3);
        goto LAB_0061e660;
      }
LAB_0061e664:
      *piVar11 = iVar9;
      piVar11[1] = 0;
      piVar11[2] = iVar5;
      gost_init(piVar11 + 3,iVar10);
      ppiVar8 = (int **)(*param_2)[2];
      (*(code *)PTR_memcpy_006aabf4)(param_1 + 4,ppiVar8,unaff_s4);
      GOST_CIPHER_PARAMS_free(param_2);
      iVar3 = 1;
      goto LAB_0061e6b8;
    }
LAB_0061e750:
    ppiVar8 = (int **)&DAT_0000006a;
    ERR_GOST_error(0x67,0x6a,"gost_crypt.c",0x9c);
  }
  GOST_CIPHER_PARAMS_free(param_2);
  iVar3 = -1;
LAB_0061e6b8:
  if (local_1c == *(int *)puStack_4c) {
    return iVar3;
  }
  iVar3 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar10 = *(int *)(iVar3 + 0xc);
  iStack_5c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = *(int *)(iVar10 + 0x103c);
  ppiStack_58 = param_2;
  piStack_54 = piVar11;
  piStack_50 = param_1;
  iStack_48 = unaff_s4;
  if (iVar3 == 0) {
    ERR_GOST_error(0x8c,0x74,"gost_crypt.c",0x240);
    while (iStack_5c != *(int *)puVar1) {
      (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0061ea0c:
      mac_block(iVar10,iVar10 + 0x1020,unaff_s5);
      puVar2 = PTR_memcpy_006aabf4;
      *(uint *)(iVar10 + 0x1030) = (*(uint *)(iVar10 + 0x1030) & 0x3ff) + 8;
      (*(code *)puVar2)(unaff_s5,unaff_s6,piVar11);
      *(int **)(iVar10 + 0x1038) = piVar11;
LAB_0061e8bc:
      if ((int)piVar11 < 8) {
        (*(code *)PTR_memset_006aab00)
                  ((undefined *)((int)piVar11 + iVar10 + 0x1028),0,8 - (int)piVar11);
      }
      if ((*(int *)(iVar10 + 0x1034) != 0) && (*(int *)(iVar10 + 0x1030) == 0x400)) {
        cryptopro_key_meshing(iVar10,&uStack_64);
      }
      mac_block(iVar10,iVar10 + 0x1020,unaff_s5);
      *(uint *)(iVar10 + 0x1030) = (*(uint *)(iVar10 + 0x1030) & 0x3ff) + 8;
LAB_0061e860:
      get_mac(iVar10 + 0x1020,0x20,ppiVar8);
      iVar3 = 1;
    }
    return iVar3;
  }
  piVar11 = *(int **)(iVar10 + 0x1038);
  if (*(int *)(iVar10 + 0x1030) != 0) {
    if (piVar11 == (int *)0x0) goto LAB_0061e860;
    unaff_s5 = iVar10 + 0x1028;
    goto LAB_0061e8bc;
  }
  if (piVar11 == (int *)0x0) goto LAB_0061e860;
  unaff_s6 = &uStack_64;
  uStack_64 = 0;
  uStack_60 = 0;
  if (&DAT_00000008 <= piVar11) {
    unaff_s5 = iVar10 + 0x1028;
    if (piVar11 == (int *)&DAT_00000008) goto LAB_0061ea0c;
    *(int **)(iVar10 + 0x1038) = piVar11;
    goto LAB_0061e8bc;
  }
  *(undefined *)((int)piVar11 + iVar10 + 0x1028) = 0;
  if ((undefined *)((int)piVar11 + 1) != (undefined *)0x8) {
    ((undefined *)((int)piVar11 + 1))[iVar10 + 0x1028] = 0;
    if ((undefined *)((int)piVar11 + 2) != (undefined *)0x8) {
      ((undefined *)((int)piVar11 + 2))[iVar10 + 0x1028] = 0;
      if ((undefined *)((int)piVar11 + 3) != (undefined *)0x8) {
        ((undefined *)((int)piVar11 + 3))[iVar10 + 0x1028] = 0;
        if (piVar11 + 1 != (int *)&DAT_00000008) {
          *(undefined *)((int)(piVar11 + 1) + iVar10 + 0x1028) = 0;
          if (((undefined *)((int)piVar11 + 5) != (undefined *)0x8) &&
             (((undefined *)((int)piVar11 + 5))[iVar10 + 0x1028] = 0, piVar11 == (int *)0x1)) {
            *(undefined *)(iVar10 + 0x102f) = 0;
          }
        }
      }
    }
  }
  unaff_s5 = iVar10 + 0x1028;
  unaff_s6 = (undefined4 *)((int)&iStack_5c - (int)piVar11);
  goto LAB_0061ea0c;
}

