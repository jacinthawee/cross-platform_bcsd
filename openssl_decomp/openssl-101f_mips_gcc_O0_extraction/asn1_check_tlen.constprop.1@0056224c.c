
uint asn1_check_tlen_constprop_1
               (undefined4 *param_1,uchar **param_2,undefined *param_3,int *param_4,byte *param_5,
               undefined4 *param_6,uchar **param_7,undefined4 param_8,char *param_9)

{
  bool bVar1;
  undefined *puVar2;
  uchar *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  uchar **ppuVar10;
  undefined4 uVar11;
  int *pclass;
  int iVar12;
  uchar **ptag;
  uchar *puStack_a8;
  int iStack_a4;
  int iStack_a0;
  int iStack_9c;
  uchar *puStack_98;
  uint uStack_94;
  char *pcStack_90;
  uchar **ppuStack_8c;
  undefined *puStack_88;
  undefined4 *puStack_84;
  undefined4 *puStack_80;
  uchar **ppuStack_7c;
  undefined *puStack_78;
  int *piStack_74;
  byte *pbStack_70;
  code *pcStack_6c;
  uchar **in_stack_ffffffa8;
  uchar *local_3c;
  int local_38;
  uchar **local_34;
  uchar **local_30;
  int *local_2c;
  
  puStack_88 = PTR___stack_chk_guard_006aabf0;
  ppuStack_8c = (uchar **)*param_6;
  local_2c = *(int **)PTR___stack_chk_guard_006aabf0;
  local_30 = ppuStack_8c;
  if (param_9 == (char *)0x0) {
    pclass = &local_38;
    ptag = &local_3c;
    in_stack_ffffffa8 = param_7;
    uVar7 = ASN1_get_object((uchar **)&local_30,(long *)&local_34,(int *)ptag,pclass,(long)param_7);
    if ((uVar7 & 0x80) == 0) goto LAB_005622fc;
    ptag = (uchar **)0x66;
    pclass = (int *)0x0;
    in_stack_ffffffa8 = (uchar **)0x51a;
    param_7 = (uchar **)&DAT_00000068;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd);
    uVar4 = 0;
  }
  else {
    if (*param_9 == '\0') {
      in_stack_ffffffa8 = param_7;
      uVar7 = ASN1_get_object((uchar **)&local_30,(long *)&local_34,(int *)&local_3c,&local_38,
                              (long)param_7);
      uVar4 = uVar7 & 0x81;
      *(int *)(param_9 + 0x10) = local_38;
      ppuVar10 = (uchar **)((int)local_30 - (int)ppuStack_8c);
      *(uint *)(param_9 + 4) = uVar7;
      *(uchar ***)(param_9 + 8) = local_34;
      *(uchar ***)(param_9 + 0x14) = ppuVar10;
      *(uchar **)(param_9 + 0xc) = local_3c;
      pclass = (int *)0x1;
      *param_9 = '\x01';
      ptag = ppuVar10;
      if ((uVar4 == 0) && (ptag = param_7, (int)param_7 < (int)((int)local_34 + (int)ppuVar10))) {
        ptag = (uchar **)0x9b;
        pclass = (int *)0x0;
        in_stack_ffffffa8 = (uchar **)0x511;
        param_7 = (uchar **)&DAT_00000068;
        (*(code *)PTR_ERR_put_error_006a9030)(0xd);
        *param_9 = '\0';
        goto LAB_00562358;
      }
    }
    else {
      local_34 = *(uchar ***)(param_9 + 8);
      local_38 = *(int *)(param_9 + 0x10);
      local_3c = *(uchar **)(param_9 + 0xc);
      local_30 = (uchar **)((int)ppuStack_8c + *(int *)(param_9 + 0x14));
      uVar7 = *(uint *)(param_9 + 4);
      ptag = local_34;
      pclass = param_4;
    }
    if ((uVar7 & 0x80) == 0) {
LAB_005622fc:
      if ((uVar7 & 1) != 0) {
        ppuStack_8c = (uchar **)((int)param_7 - ((int)local_30 - (int)ppuStack_8c));
        local_34 = ppuStack_8c;
      }
      if (param_4 != (int *)0x0) {
        *(char *)param_4 = (char)(uVar7 & 1);
      }
      if (param_5 != (byte *)0x0) {
        *param_5 = (byte)uVar7 & 0x20;
      }
      if (param_1 != (undefined4 *)0x0) {
        *param_1 = local_34;
      }
      if (param_3 != (undefined *)0x0) {
        *param_3 = (char)local_38;
      }
      if (param_2 != (uchar **)0x0) {
        *param_2 = local_3c;
      }
      uVar4 = 1;
      *param_6 = local_30;
    }
    else {
      ptag = (uchar **)0x66;
      pclass = (int *)0x0;
      in_stack_ffffffa8 = (uchar **)0x51a;
      param_7 = (uchar **)&DAT_00000068;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd);
      uVar4 = 0;
      *param_9 = '\0';
    }
  }
LAB_00562358:
  if (local_2c == *(int **)puStack_88) {
    return uVar4;
  }
  pcStack_6c = asn1_collect_constprop_0;
  piVar9 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  pcStack_90 = param_9;
  uVar7 = (uint)pclass & 1;
  puStack_a8 = *param_7;
  pbStack_70 = param_5;
  puStack_84 = param_6;
  uStack_94 = *(uint *)PTR___stack_chk_guard_006aabf0;
  puStack_80 = param_1;
  ppuStack_7c = param_2;
  puStack_78 = param_3;
  piStack_74 = param_4;
  if (piVar9 == (int *)0x0) {
    if (uVar7 == 0) {
      uVar4 = 1;
      *param_7 = puStack_a8 + (int)ptag;
      goto LAB_00562720;
    }
    if (0 < (int)ptag) goto LAB_00562550;
  }
  else {
    if (0 < (int)ptag) {
LAB_00562550:
      bVar1 = 4 < (int)in_stack_ffffffa8;
LAB_005625b0:
      do {
        puVar3 = puStack_a8;
        if (((ptag != (uchar **)0x1) && (*puStack_a8 == '\0')) && (puStack_a8[1] == '\0')) {
          puStack_a8 = puStack_a8 + 2;
          if (uVar7 != 0) goto LAB_00562784;
          uVar11 = 0x9f;
          uVar6 = 0x49c;
          goto LAB_005626a8;
        }
        puStack_98 = puStack_a8;
        uVar5 = ASN1_get_object(&puStack_98,&iStack_9c,&iStack_a4,&iStack_a0,(long)ptag);
        uVar4 = uVar5 & 0x80;
        if (uVar4 != 0) {
          uVar4 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x68,0x66,s_tasn_dec_c_0066ab0c,0x51a);
          (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x6a,0x3a,s_tasn_dec_c_0066ab0c,0x4a6);
          goto LAB_00562720;
        }
        puStack_a8 = puStack_98;
        iVar12 = iStack_9c;
        if ((uVar5 & 1) != 0) {
          iVar12 = (int)ptag - ((int)puStack_98 - (int)puVar3);
        }
        if ((uVar5 & 0x20) == 0) {
          if (iVar12 != 0) {
            if (piVar9 != (int *)0x0) {
              iVar8 = *piVar9;
              uVar4 = (*(code *)PTR_BUF_MEM_grow_clean_006a8c2c)(piVar9,iVar8 + iVar12);
              if (uVar4 == 0) {
                (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x8c,0x41,s_tasn_dec_c_0066ab0c,0x4cc);
                goto LAB_00562720;
              }
              (*(code *)PTR_memcpy_006aabf4)(piVar9[1] + iVar8,puStack_a8,iVar12);
            }
            puStack_a8 = puStack_a8 + iVar12;
            ptag = (uchar **)((int)ptag - ((int)puStack_a8 - (int)puVar3));
            if ((int)ptag < 1) break;
            goto LAB_005625b0;
          }
        }
        else {
          if (bVar1) {
            (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x6a,0xc5,s_tasn_dec_c_0066ab0c,0x4b0);
            goto LAB_00562720;
          }
          uVar4 = asn1_collect_constprop_0
                            (piVar9,&puStack_a8,iVar12,(byte)uVar5 & 1,
                             (undefined *)((int)in_stack_ffffffa8 + 1));
          if (uVar4 == 0) goto LAB_00562720;
        }
        ptag = (uchar **)((int)ptag - ((int)puStack_a8 - (int)puVar3));
      } while (0 < (int)ptag);
    }
    if (uVar7 == 0) {
LAB_00562784:
      uVar4 = 1;
      *param_7 = puStack_a8;
      goto LAB_00562720;
    }
  }
  uVar11 = 0x89;
  uVar6 = 0x4bd;
LAB_005626a8:
  uVar4 = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x6a,uVar11,s_tasn_dec_c_0066ab0c,uVar6);
LAB_00562720:
  if (uStack_94 == *(uint *)puVar2) {
    return uVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (0x1e < uStack_94) {
    return 0;
  }
  return *(uint *)(tag2bit + uStack_94 * 4);
}

