
uint asn1_check_tlen(long **param_1,int *param_2,undefined *param_3,char ******param_4,byte *param_5
                    ,long **param_6,char ******param_7,char *****param_8,char ******param_9,
                    char param_10,char *param_11)

{
  bool bVar1;
  undefined *puVar2;
  char ****ppppcVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  char *****pppppcVar10;
  undefined4 uVar11;
  char ******pclass;
  int iVar12;
  char *****ptag;
  char ****ppppcStack_110;
  int iStack_10c;
  int iStack_108;
  int iStack_104;
  char ****ppppcStack_100;
  uint uStack_fc;
  char *****pppppcStack_f4;
  undefined *puStack_f0;
  undefined4 *puStack_e8;
  char ******ppppppcStack_e4;
  char ******ppppppcStack_e0;
  char *pcStack_dc;
  char ******ppppppcStack_d8;
  code *pcStack_d4;
  char *****in_stack_ffffff40;
  char *****pppppcStack_a4;
  char *****pppppcStack_a0;
  char *****pppppcStack_9c;
  char *****pppppcStack_98;
  int *piStack_94;
  char *pcStack_90;
  char ******ppppppcStack_8c;
  undefined *puStack_88;
  long **pplStack_84;
  char ******ppppppcStack_80;
  int iStack_7c;
  long **pplStack_78;
  int *piStack_74;
  undefined *puStack_70;
  code *pcStack_6c;
  char ******in_stack_ffffffa8;
  undefined4 *puStack_54;
  char *****local_50;
  char *pcStack_48;
  char *****local_3c;
  char ******local_38;
  char ******local_34;
  char ******local_30;
  undefined4 *local_2c;
  
  puStack_88 = PTR___stack_chk_guard_006a9ae8;
  local_50 = (char *****)&_gp;
  ppppppcStack_8c = (char ******)*param_6;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  iStack_7c = (int)param_10;
  local_30 = ppppppcStack_8c;
  if (param_11 == (char *)0x0) {
    pcStack_dc = (char *)&local_38;
    ppppppcStack_e0 = &local_3c;
    ppppppcStack_e4 = (char ******)&local_34;
    ppppppcStack_d8 = param_7;
    uVar7 = ASN1_get_object((uchar **)&local_30,(long *)ppppppcStack_e4,(int *)ppppppcStack_e0,
                            (int *)pcStack_dc,(long)param_7);
    if ((uVar7 & 0x80) == 0) {
LAB_0055e194:
      if (-1 < (int)param_8) {
        if ((param_8 != local_3c) || (local_38 != param_9)) {
          uVar4 = 0xffffffff;
          if (iStack_7c != 0) goto LAB_0055e1ec;
          if (param_11 != (char *)0x0) {
            *param_11 = '\0';
          }
          ppppppcStack_e0 = (char ******)&DAT_000000a8;
          ppppppcStack_d8 = (char ******)&DAT_000004af;
          goto LAB_0055e1d4;
        }
        if (param_11 != (char *)0x0) {
          *param_11 = '\0';
        }
      }
      if ((uVar7 & 1) != 0) {
        ppppppcStack_8c = (char ******)((int)param_7 - ((int)local_30 - (int)ppppppcStack_8c));
        ppppppcStack_e4 = param_7;
        local_34 = ppppppcStack_8c;
      }
      if (param_4 != (char ******)0x0) {
        *(char *)param_4 = (char)(uVar7 & 1);
      }
      if (param_5 != (byte *)0x0) {
        *param_5 = (byte)uVar7 & 0x20;
      }
      if (param_1 != (long **)0x0) {
        *param_1 = (long *)local_34;
      }
      if (param_3 != (undefined *)0x0) {
        *param_3 = (char)local_38;
      }
      if (param_2 != (int *)0x0) {
        *param_2 = (int)local_3c;
      }
      *param_6 = (long *)local_30;
      uVar4 = 1;
    }
    else {
      ppppppcStack_e0 = (char ******)0x66;
      ppppppcStack_d8 = (char ******)0x4a3;
LAB_0055e1d4:
      pcStack_dc = s_tasn_dec_c_0066a0bc;
      ppppppcStack_e4 = (char ******)&DAT_00000068;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
      uVar4 = 0;
    }
  }
  else if (*param_11 == '\0') {
    pcStack_dc = (char *)&local_38;
    in_stack_ffffffa8 = param_7;
    uVar7 = ASN1_get_object((uchar **)&local_30,(long *)&local_34,(int *)&local_3c,(int *)pcStack_dc
                            ,(long)param_7);
    uVar4 = uVar7 & 0x81;
    *(char *******)(param_11 + 0x10) = local_38;
    *(uint *)(param_11 + 4) = uVar7;
    *(char *******)(param_11 + 8) = local_34;
    *(char ******)(param_11 + 0xc) = local_3c;
    ppppppcStack_e0 = (char ******)0x1;
    *(int *)(param_11 + 0x14) = (int)local_30 - (int)ppppppcStack_8c;
    *param_11 = '\x01';
    ppppppcStack_e4 = local_34;
    if ((uVar4 != 0) ||
       (ppppppcStack_e4 = param_7,
       (int)((int)local_34 + ((int)local_30 - (int)ppppppcStack_8c)) <= (int)param_7))
    goto LAB_0055e188;
    ppppppcStack_e0 = (char ******)&DAT_0000009b;
    pcStack_dc = s_tasn_dec_c_0066a0bc;
    ppppppcStack_d8 = (char ******)0x49b;
    ppppppcStack_e4 = (char ******)&DAT_00000068;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
    *param_11 = '\0';
  }
  else {
    ppppppcStack_e0 = *(char *******)(param_11 + 8);
    local_38 = *(char *******)(param_11 + 0x10);
    local_3c = *(char ******)(param_11 + 0xc);
    local_30 = (char ******)((int)ppppppcStack_8c + *(int *)(param_11 + 0x14));
    uVar7 = *(uint *)(param_11 + 4);
    ppppppcStack_e4 = local_38;
    pcStack_dc = (char *)param_4;
    local_34 = ppppppcStack_e0;
LAB_0055e188:
    ppppppcStack_d8 = in_stack_ffffffa8;
    if ((uVar7 & 0x80) == 0) goto LAB_0055e194;
    ppppppcStack_e0 = (char ******)0x66;
    pcStack_dc = s_tasn_dec_c_0066a0bc;
    ppppppcStack_d8 = (char ******)0x4a3;
    ppppppcStack_e4 = (char ******)&DAT_00000068;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
    uVar4 = 0;
    *param_11 = '\0';
  }
LAB_0055e1ec:
  if (local_2c == *(undefined4 **)puStack_88) {
    return uVar4;
  }
  pcStack_6c = asn1_check_tlen_constprop_1;
  puStack_e8 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_f0 = PTR___stack_chk_guard_006a9ae8;
  pplStack_84 = param_6;
  pcStack_90 = param_11;
  pppppcStack_f4 = (char *****)*puStack_54;
  piStack_94 = *(int **)PTR___stack_chk_guard_006a9ae8;
  pppppcStack_98 = pppppcStack_f4;
  ppppppcStack_80 = param_4;
  pplStack_78 = param_1;
  piStack_74 = param_2;
  puStack_70 = param_3;
  if (pcStack_48 == (char *)0x0) {
    pclass = &pppppcStack_a0;
    ptag = (char *****)&pppppcStack_a4;
    in_stack_ffffff40 = local_50;
    uVar7 = ASN1_get_object((uchar **)&pppppcStack_98,(long *)&pppppcStack_9c,(int *)ptag,
                            (int *)pclass,(long)&_gp);
    if ((uVar7 & 0x80) == 0) goto LAB_0055e48c;
    ptag = (char *****)0x66;
    pclass = (char ******)0x0;
    in_stack_ffffff40 = (char *****)0x4a3;
    local_50 = (char *****)&DAT_00000068;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
    uVar4 = 0;
  }
  else {
    if (*pcStack_48 == '\0') {
      in_stack_ffffff40 = local_50;
      uVar7 = ASN1_get_object((uchar **)&pppppcStack_98,(long *)&pppppcStack_9c,
                              (int *)&pppppcStack_a4,(int *)&pppppcStack_a0,(long)&_gp);
      uVar4 = uVar7 & 0x81;
      *(char ******)(pcStack_48 + 0x10) = pppppcStack_a0;
      pppppcVar10 = (char *****)((int)pppppcStack_98 - (int)pppppcStack_f4);
      *(uint *)(pcStack_48 + 4) = uVar7;
      *(char ******)(pcStack_48 + 8) = pppppcStack_9c;
      *(char ******)(pcStack_48 + 0x14) = pppppcVar10;
      *(char ******)(pcStack_48 + 0xc) = pppppcStack_a4;
      pclass = (char ******)0x1;
      *pcStack_48 = '\x01';
      ptag = pppppcVar10;
      if ((uVar4 == 0) &&
         (ptag = local_50, 0x6aede0 < (int)((int)pppppcStack_9c + (int)pppppcVar10))) {
        ptag = (char *****)&DAT_0000009b;
        pclass = (char ******)0x0;
        in_stack_ffffff40 = (char *****)0x49b;
        local_50 = (char *****)&DAT_00000068;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
        *pcStack_48 = '\0';
        goto LAB_0055e4e8;
      }
    }
    else {
      pppppcStack_9c = *(char ******)(pcStack_48 + 8);
      pppppcStack_a0 = *(char ******)(pcStack_48 + 0x10);
      pppppcStack_a4 = *(char ******)(pcStack_48 + 0xc);
      pppppcStack_98 = (char *****)((int)pppppcStack_f4 + *(int *)(pcStack_48 + 0x14));
      uVar7 = *(uint *)(pcStack_48 + 4);
      ptag = pppppcStack_9c;
      pclass = (char ******)pcStack_dc;
    }
    if ((uVar7 & 0x80) == 0) {
LAB_0055e48c:
      if ((uVar7 & 1) != 0) {
        pppppcStack_f4 = (char *****)(&_gp + -((int)pppppcStack_98 - (int)pppppcStack_f4));
        pppppcStack_9c = pppppcStack_f4;
      }
      if ((char ******)pcStack_dc != (char ******)0x0) {
        *pcStack_dc = (char)(uVar7 & 1);
      }
      if (ppppppcStack_d8 != (char ******)0x0) {
        *(byte *)ppppppcStack_d8 = (byte)uVar7 & 0x20;
      }
      if (puStack_e8 != (undefined4 *)0x0) {
        *puStack_e8 = pppppcStack_9c;
      }
      if (ppppppcStack_e0 != (char ******)0x0) {
        *(byte *)ppppppcStack_e0 = (byte)pppppcStack_a0;
      }
      if (ppppppcStack_e4 != (char ******)0x0) {
        *ppppppcStack_e4 = pppppcStack_a4;
      }
      uVar4 = 1;
      *puStack_54 = pppppcStack_98;
    }
    else {
      ptag = (char *****)0x66;
      pclass = (char ******)0x0;
      in_stack_ffffff40 = (char *****)0x4a3;
      local_50 = (char *****)&DAT_00000068;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
      uVar4 = 0;
      *pcStack_48 = '\0';
    }
  }
LAB_0055e4e8:
  if (piStack_94 == *(int **)puStack_f0) {
    return uVar4;
  }
  pcStack_d4 = asn1_collect_constprop_0;
  piVar9 = piStack_94;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  uVar7 = (uint)pclass & 1;
  ppppcStack_110 = *local_50;
  uStack_fc = *(uint *)PTR___stack_chk_guard_006a9ae8;
  if (piVar9 == (int *)0x0) {
    if (uVar7 == 0) {
      uVar4 = 1;
      *local_50 = (char ****)((int)ppppcStack_110 + (int)ptag);
      goto LAB_0055e8b0;
    }
    if (0 < (int)ptag) goto LAB_0055e6e0;
  }
  else {
    if (0 < (int)ptag) {
LAB_0055e6e0:
      bVar1 = 4 < (int)in_stack_ffffff40;
LAB_0055e740:
      do {
        ppppcVar3 = ppppcStack_110;
        if (((ptag != (char *****)0x1) && (*(char *)ppppcStack_110 == '\0')) &&
           (*(char *)((int)ppppcStack_110 + 1) == '\0')) {
          ppppcStack_110 = (char ****)((int)ppppcStack_110 + 2);
          if (uVar7 != 0) goto LAB_0055e914;
          uVar11 = 0x9f;
          uVar6 = 0x435;
          goto LAB_0055e838;
        }
        ppppcStack_100 = ppppcStack_110;
        uVar5 = ASN1_get_object((uchar **)&ppppcStack_100,&iStack_104,&iStack_10c,&iStack_108,
                                (long)ptag);
        uVar4 = uVar5 & 0x80;
        if (uVar4 != 0) {
          uVar4 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,0x66,s_tasn_dec_c_0066a0bc,0x4a3);
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x6a,0x3a,s_tasn_dec_c_0066a0bc,0x43e);
          goto LAB_0055e8b0;
        }
        ppppcStack_110 = ppppcStack_100;
        iVar12 = iStack_104;
        if ((uVar5 & 1) != 0) {
          iVar12 = (int)ptag - ((int)ppppcStack_100 - (int)ppppcVar3);
        }
        if ((uVar5 & 0x20) == 0) {
          if (iVar12 != 0) {
            if (piVar9 != (int *)0x0) {
              iVar8 = *piVar9;
              uVar4 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(piVar9,iVar8 + iVar12);
              if (uVar4 == 0) {
                (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x8c,0x41,s_tasn_dec_c_0066a0bc,0x45c);
                goto LAB_0055e8b0;
              }
              (*(code *)PTR_memcpy_006a9aec)(piVar9[1] + iVar8,ppppcStack_110,iVar12);
            }
            ppppcStack_110 = (char ****)((int)ppppcStack_110 + iVar12);
            ptag = (char *****)((int)ptag - ((int)ppppcStack_110 - (int)ppppcVar3));
            if ((int)ptag < 1) break;
            goto LAB_0055e740;
          }
        }
        else {
          if (bVar1) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x6a,0xc5,s_tasn_dec_c_0066a0bc,0x445);
            goto LAB_0055e8b0;
          }
          uVar4 = asn1_collect_constprop_0
                            (piVar9,&ppppcStack_110,iVar12,(byte)uVar5 & 1,
                             (undefined *)((int)in_stack_ffffff40 + 1));
          if (uVar4 == 0) goto LAB_0055e8b0;
        }
        ptag = (char *****)((int)ptag - ((int)ppppcStack_110 - (int)ppppcVar3));
      } while (0 < (int)ptag);
    }
    if (uVar7 == 0) {
LAB_0055e914:
      uVar4 = 1;
      *local_50 = ppppcStack_110;
      goto LAB_0055e8b0;
    }
  }
  uVar11 = 0x89;
  uVar6 = 0x44f;
LAB_0055e838:
  uVar4 = 0;
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x6a,uVar11,s_tasn_dec_c_0066a0bc,uVar6);
LAB_0055e8b0:
  if (uStack_fc == *(uint *)puVar2) {
    return uVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (0x1e < uStack_fc) {
    return 0;
  }
  return *(uint *)(tag2bit + uStack_fc * 4);
}

