
undefined4 *
X509_OBJECT_idx_by_subject
          (undefined4 param_1,undefined4 *****param_2,X509_ALGOR *param_3,int *param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *****pppppuVar7;
  int iVar8;
  code *pcVar9;
  undefined4 *****pppppuStack_27c;
  X509 *pXStack_278;
  undefined auStack_274 [60];
  X509_ALGOR *pXStack_238;
  undefined auStack_218 [180];
  int iStack_164;
  undefined *puStack_160;
  undefined4 *****pppppuStack_124;
  undefined **ppuStack_120;
  undefined auStack_11c [8];
  X509_ALGOR *pXStack_114;
  undefined auStack_f4 [20];
  X509_ALGOR *pXStack_e0;
  undefined *apuStack_c0 [19];
  undefined *apuStack_74 [26];
  int iStack_c;
  
  puStack_160 = PTR___stack_chk_guard_006aabf0;
  iStack_c = *(int *)PTR___stack_chk_guard_006aabf0;
  pppppuStack_124 = param_2;
  if (param_2 == (undefined4 *****)0x1) {
    apuStack_74[0] = auStack_f4;
    ppuStack_120 = apuStack_74;
    pXStack_e0 = param_3;
LAB_005832b0:
    pppppuStack_27c = &pppppuStack_124;
    puVar3 = (undefined4 *)(*(code *)PTR_sk_find_006a906c)();
  }
  else {
    if (param_2 == (undefined4 *****)&SUB_00000002) {
      apuStack_c0[0] = auStack_11c;
      ppuStack_120 = apuStack_c0;
      pXStack_114 = param_3;
      goto LAB_005832b0;
    }
    puVar3 = (undefined4 *)0xffffffff;
    pppppuStack_27c = param_2;
  }
  if (iStack_c == *(int *)puStack_160) {
    return puVar3;
  }
  iVar6 = iStack_c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iStack_164 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (pppppuStack_27c == (undefined4 *****)0x1) {
    pXStack_278 = (X509 *)(auStack_218 + 0x4c);
    auStack_218._76_4_ = (NAME_CONSTRAINTS *)(auStack_274 + 0x28);
    pXStack_238 = param_3;
  }
  else {
    puVar3 = (undefined4 *)0xffffffff;
    if (pppppuStack_27c != (undefined4 *****)&SUB_00000002) goto LAB_00583414;
    pXStack_278 = (X509 *)auStack_218;
    auStack_218._0_4_ = (X509_CINF *)auStack_274;
    auStack_274._8_4_ = param_3;
  }
  puVar3 = (undefined4 *)(*(code *)PTR_sk_find_006a906c)(iVar6,&pppppuStack_27c);
  puVar1 = PTR_sk_num_006a7f2c;
  if ((-1 < (int)puVar3) && (param_4 != (int *)0x0)) {
    iVar8 = (int)puVar3 + 1;
    *param_4 = 1;
    iVar4 = (*(code *)puVar1)(iVar6);
    if (iVar8 < iVar4) {
      do {
        puVar5 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(iVar6,iVar8);
        pppppuVar7 = (undefined4 *****)*puVar5;
        if (pppppuVar7 != pppppuStack_27c) break;
        if (pppppuVar7 == (undefined4 *****)0x1) {
          iVar4 = X509_subject_name_cmp((X509 *)puVar5[1],pXStack_278);
LAB_005833e0:
          if (iVar4 != 0) break;
        }
        else if (pppppuVar7 == (undefined4 *****)&SUB_00000002) {
          iVar4 = X509_CRL_cmp((X509_CRL *)puVar5[1],(X509_CRL *)pXStack_278);
          goto LAB_005833e0;
        }
        puVar1 = PTR_sk_num_006a7f2c;
        iVar8 = iVar8 + 1;
        *param_4 = *param_4 + 1;
        iVar4 = (*(code *)puVar1)(iVar6);
      } while (iVar8 < iVar4);
    }
  }
LAB_00583414:
  if (iStack_164 != *(int *)puVar2) {
    iVar6 = iStack_164;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    puVar3 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x14,"x509_lu.c",0x45);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      pcVar9 = *(code **)(iVar6 + 4);
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = iVar6;
      puVar3[3] = 0;
      puVar3[4] = 0;
      if ((pcVar9 != (code *)0x0) && (iVar6 = (*pcVar9)(), iVar6 == 0)) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
        puVar3 = (undefined4 *)0x0;
      }
    }
    return puVar3;
  }
  return puVar3;
}

