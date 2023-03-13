
int ASN1_item_i2d(ASN1_VALUE *val,uchar **out,ASN1_ITEM *it)

{
  bool bVar1;
  undefined *puVar2;
  char ****ppppcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  char *****pppppcVar11;
  undefined4 uVar12;
  char ******pclass;
  int unaff_s2;
  ASN1_VALUE **unaff_s4;
  uchar *unaff_s5;
  char *****ptag;
  char ****ppppcStack_160;
  int iStack_15c;
  int iStack_158;
  int iStack_154;
  char ****ppppcStack_150;
  uint uStack_14c;
  char *****pppppcStack_144;
  undefined *puStack_140;
  undefined4 *puStack_138;
  char ******ppppppcStack_134;
  char ******ppppppcStack_130;
  char *pcStack_12c;
  char ******ppppppcStack_128;
  code *pcStack_124;
  char *****in_stack_fffffef0;
  char *****pppppcStack_f4;
  char *****pppppcStack_f0;
  char *****pppppcStack_ec;
  char *****pppppcStack_e8;
  int *piStack_e4;
  uchar *puStack_e0;
  char ******ppppppcStack_dc;
  undefined *puStack_d8;
  char ******ppppppcStack_d0;
  int iStack_cc;
  long **pplStack_c8;
  char *pcStack_c4;
  ASN1_ITEM *pAStack_c0;
  code *pcStack_bc;
  char ******in_stack_ffffff58;
  undefined4 *puStack_a4;
  char *****pppppcStack_a0;
  char *pcStack_98;
  char *****pppppcStack_8c;
  char ******ppppppcStack_88;
  char ******ppppppcStack_84;
  char ******ppppppcStack_80;
  undefined4 *puStack_7c;
  uchar **ppuStack_78;
  undefined *puStack_74;
  int iStack_70;
  ASN1_ITEM *pAStack_6c;
  ASN1_VALUE **ppAStack_68;
  uchar *puStack_64;
  byte *pbVar13;
  long **pplStack_3c;
  char ******local_38;
  char *****pppppcStack_34;
  char ******ppppppcStack_30;
  undefined4 local_2c;
  uchar *local_28;
  long **local_24;
  
  puStack_74 = PTR___stack_chk_guard_006a9ae8;
  local_38 = (char ******)&_gp;
  local_24 = *(long ***)PTR___stack_chk_guard_006a9ae8;
  ppppppcStack_d0 = (char ******)0xffffffff;
  pAStack_c0 = it;
  local_2c = val;
  if ((out == (uchar **)0x0) || (unaff_s4 = (ASN1_VALUE **)&local_2c, *out != (uchar *)0x0)) {
    pbVar13 = (byte *)0x0;
    pcStack_c4 = (char *)out;
    iVar4 = ASN1_item_ex_i2d((ASN1_VALUE **)&local_2c,out,it,-1,0);
  }
  else {
    pbVar13 = (byte *)0x0;
    ppppppcStack_d0 = (char ******)0xffffffff;
    pcStack_c4 = (char *)0x0;
    unaff_s2 = ASN1_item_ex_i2d(unaff_s4,(uchar **)0x0,it,-1,0);
    iVar4 = unaff_s2;
    if (0 < unaff_s2) {
      pAStack_c0 = (ASN1_ITEM *)&DAT_0000006e;
      pcStack_c4 = "tasn_enc.c";
      unaff_s5 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(unaff_s2);
      if (unaff_s5 == (uchar *)0x0) {
        iVar4 = -1;
      }
      else {
        ppppppcStack_d0 = (char ******)0xffffffff;
        pbVar13 = (byte *)0x0;
        pcStack_c4 = (char *)&local_28;
        pAStack_c0 = it;
        local_28 = unaff_s5;
        ASN1_item_ex_i2d(unaff_s4,(uchar **)pcStack_c4,it,-1,0);
        *out = unaff_s5;
      }
    }
  }
  if (local_24 == *(long ***)puStack_74) {
    return iVar4;
  }
  pplStack_c8 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_e0 = local_28;
  puStack_d8 = PTR___stack_chk_guard_006a9ae8;
  pppppcStack_a0 = (char *****)&_gp;
  ppppppcStack_dc = (char ******)*pplStack_3c;
  puStack_7c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  iStack_cc = (int)(char)local_2c;
  ppppppcStack_80 = ppppppcStack_dc;
  ppuStack_78 = out;
  iStack_70 = unaff_s2;
  pAStack_6c = it;
  ppAStack_68 = unaff_s4;
  puStack_64 = unaff_s5;
  if (local_28 == (uchar *)0x0) {
    pcStack_12c = (char *)&ppppppcStack_88;
    ppppppcStack_130 = &pppppcStack_8c;
    ppppppcStack_134 = (char ******)&ppppppcStack_84;
    ppppppcStack_128 = local_38;
    uVar8 = ASN1_get_object((uchar **)&ppppppcStack_80,(long *)ppppppcStack_134,
                            (int *)ppppppcStack_130,(int *)pcStack_12c,(long)&_gp);
    if ((uVar8 & 0x80) == 0) {
LAB_0055e194:
      if (-1 < (int)pppppcStack_34) {
        if ((pppppcStack_34 != pppppcStack_8c) || (ppppppcStack_88 != ppppppcStack_30)) {
          uVar5 = 0xffffffff;
          if (iStack_cc != 0) goto LAB_0055e1ec;
          if (puStack_e0 != (uchar *)0x0) {
            *puStack_e0 = '\0';
          }
          ppppppcStack_130 = (char ******)&DAT_000000a8;
          ppppppcStack_128 = (char ******)&DAT_000004af;
          goto LAB_0055e1d4;
        }
        if (puStack_e0 != (uchar *)0x0) {
          *puStack_e0 = '\0';
        }
      }
      if ((uVar8 & 1) != 0) {
        ppppppcStack_dc = (char ******)(&_gp + -((int)ppppppcStack_80 - (int)ppppppcStack_dc));
        ppppppcStack_134 = local_38;
        ppppppcStack_84 = ppppppcStack_dc;
      }
      if (ppppppcStack_d0 != (char ******)0x0) {
        *(char *)ppppppcStack_d0 = (char)(uVar8 & 1);
      }
      if (pbVar13 != (byte *)0x0) {
        *pbVar13 = (byte)uVar8 & 0x20;
      }
      if (pplStack_c8 != (long **)0x0) {
        *pplStack_c8 = (long *)ppppppcStack_84;
      }
      if (pAStack_c0 != (ASN1_ITEM *)0x0) {
        pAStack_c0->itype = (char)ppppppcStack_88;
      }
      if ((uchar **)pcStack_c4 != (uchar **)0x0) {
        *(char ******)pcStack_c4 = pppppcStack_8c;
      }
      *pplStack_3c = (long *)ppppppcStack_80;
      uVar5 = 1;
    }
    else {
      ppppppcStack_130 = (char ******)0x66;
      ppppppcStack_128 = (char ******)0x4a3;
LAB_0055e1d4:
      pcStack_12c = s_tasn_dec_c_0066a0bc;
      ppppppcStack_134 = (char ******)&DAT_00000068;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
      uVar5 = 0;
    }
  }
  else if (*local_28 == '\0') {
    pcStack_12c = (char *)&ppppppcStack_88;
    in_stack_ffffff58 = local_38;
    uVar8 = ASN1_get_object((uchar **)&ppppppcStack_80,(long *)&ppppppcStack_84,
                            (int *)&pppppcStack_8c,(int *)pcStack_12c,(long)&_gp);
    uVar5 = uVar8 & 0x81;
    *(char *******)(puStack_e0 + 0x10) = ppppppcStack_88;
    *(uint *)(puStack_e0 + 4) = uVar8;
    *(char *******)(puStack_e0 + 8) = ppppppcStack_84;
    *(char ******)(puStack_e0 + 0xc) = pppppcStack_8c;
    ppppppcStack_130 = (char ******)0x1;
    *(int *)(puStack_e0 + 0x14) = (int)ppppppcStack_80 - (int)ppppppcStack_dc;
    *puStack_e0 = '\x01';
    ppppppcStack_134 = ppppppcStack_84;
    if ((uVar5 != 0) ||
       (ppppppcStack_134 = local_38,
       (int)((int)ppppppcStack_84 + ((int)ppppppcStack_80 - (int)ppppppcStack_dc)) < 0x6aede1))
    goto LAB_0055e188;
    ppppppcStack_130 = (char ******)&DAT_0000009b;
    pcStack_12c = s_tasn_dec_c_0066a0bc;
    ppppppcStack_128 = (char ******)0x49b;
    ppppppcStack_134 = (char ******)&DAT_00000068;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
    *puStack_e0 = '\0';
  }
  else {
    ppppppcStack_130 = *(char *******)(local_28 + 8);
    ppppppcStack_88 = *(char *******)(local_28 + 0x10);
    pppppcStack_8c = *(char ******)(local_28 + 0xc);
    ppppppcStack_80 = (char ******)((int)ppppppcStack_dc + *(int *)(local_28 + 0x14));
    uVar8 = *(uint *)(local_28 + 4);
    ppppppcStack_134 = ppppppcStack_88;
    pcStack_12c = (char *)ppppppcStack_d0;
    ppppppcStack_84 = ppppppcStack_130;
LAB_0055e188:
    ppppppcStack_128 = in_stack_ffffff58;
    if ((uVar8 & 0x80) == 0) goto LAB_0055e194;
    ppppppcStack_130 = (char ******)0x66;
    pcStack_12c = s_tasn_dec_c_0066a0bc;
    ppppppcStack_128 = (char ******)0x4a3;
    ppppppcStack_134 = (char ******)&DAT_00000068;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
    uVar5 = 0;
    *puStack_e0 = '\0';
  }
LAB_0055e1ec:
  if (puStack_7c == *(undefined4 **)puStack_d8) {
    return uVar5;
  }
  pcStack_bc = asn1_check_tlen_constprop_1;
  puStack_138 = puStack_7c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_140 = PTR___stack_chk_guard_006a9ae8;
  pppppcStack_144 = (char *****)*puStack_a4;
  piStack_e4 = *(int **)PTR___stack_chk_guard_006a9ae8;
  pppppcStack_e8 = pppppcStack_144;
  if (pcStack_98 == (char *)0x0) {
    pclass = &pppppcStack_f0;
    ptag = (char *****)&pppppcStack_f4;
    in_stack_fffffef0 = pppppcStack_a0;
    uVar8 = ASN1_get_object((uchar **)&pppppcStack_e8,(long *)&pppppcStack_ec,(int *)ptag,
                            (int *)pclass,(long)&_gp);
    if ((uVar8 & 0x80) == 0) goto LAB_0055e48c;
    ptag = (char *****)0x66;
    pclass = (char ******)0x0;
    in_stack_fffffef0 = (char *****)0x4a3;
    pppppcStack_a0 = (char *****)&DAT_00000068;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
    uVar5 = 0;
  }
  else {
    if (*pcStack_98 == '\0') {
      in_stack_fffffef0 = pppppcStack_a0;
      uVar8 = ASN1_get_object((uchar **)&pppppcStack_e8,(long *)&pppppcStack_ec,
                              (int *)&pppppcStack_f4,(int *)&pppppcStack_f0,(long)&_gp);
      uVar5 = uVar8 & 0x81;
      *(char ******)(pcStack_98 + 0x10) = pppppcStack_f0;
      pppppcVar11 = (char *****)((int)pppppcStack_e8 - (int)pppppcStack_144);
      *(uint *)(pcStack_98 + 4) = uVar8;
      *(char ******)(pcStack_98 + 8) = pppppcStack_ec;
      *(char ******)(pcStack_98 + 0x14) = pppppcVar11;
      *(char ******)(pcStack_98 + 0xc) = pppppcStack_f4;
      pclass = (char ******)0x1;
      *pcStack_98 = '\x01';
      ptag = pppppcVar11;
      if ((uVar5 == 0) &&
         (ptag = pppppcStack_a0, 0x6aede0 < (int)((int)pppppcStack_ec + (int)pppppcVar11))) {
        ptag = (char *****)&DAT_0000009b;
        pclass = (char ******)0x0;
        in_stack_fffffef0 = (char *****)0x49b;
        pppppcStack_a0 = (char *****)&DAT_00000068;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
        *pcStack_98 = '\0';
        goto LAB_0055e4e8;
      }
    }
    else {
      pppppcStack_ec = *(char ******)(pcStack_98 + 8);
      pppppcStack_f0 = *(char ******)(pcStack_98 + 0x10);
      pppppcStack_f4 = *(char ******)(pcStack_98 + 0xc);
      pppppcStack_e8 = (char *****)((int)pppppcStack_144 + *(int *)(pcStack_98 + 0x14));
      uVar8 = *(uint *)(pcStack_98 + 4);
      ptag = pppppcStack_ec;
      pclass = (char ******)pcStack_12c;
    }
    if ((uVar8 & 0x80) == 0) {
LAB_0055e48c:
      if ((uVar8 & 1) != 0) {
        pppppcStack_144 = (char *****)(&_gp + -((int)pppppcStack_e8 - (int)pppppcStack_144));
        pppppcStack_ec = pppppcStack_144;
      }
      if ((char ******)pcStack_12c != (char ******)0x0) {
        *pcStack_12c = (char)(uVar8 & 1);
      }
      if (ppppppcStack_128 != (char ******)0x0) {
        *(byte *)ppppppcStack_128 = (byte)uVar8 & 0x20;
      }
      if (puStack_138 != (undefined4 *)0x0) {
        *puStack_138 = pppppcStack_ec;
      }
      if (ppppppcStack_130 != (char ******)0x0) {
        *(byte *)ppppppcStack_130 = (byte)pppppcStack_f0;
      }
      if (ppppppcStack_134 != (char ******)0x0) {
        *ppppppcStack_134 = pppppcStack_f4;
      }
      uVar5 = 1;
      *puStack_a4 = pppppcStack_e8;
    }
    else {
      ptag = (char *****)0x66;
      pclass = (char ******)0x0;
      in_stack_fffffef0 = (char *****)0x4a3;
      pppppcStack_a0 = (char *****)&DAT_00000068;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
      uVar5 = 0;
      *pcStack_98 = '\0';
    }
  }
LAB_0055e4e8:
  if (piStack_e4 == *(int **)puStack_140) {
    return uVar5;
  }
  pcStack_124 = asn1_collect_constprop_0;
  piVar10 = piStack_e4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  uVar8 = (uint)pclass & 1;
  ppppcStack_160 = *pppppcStack_a0;
  uStack_14c = *(uint *)PTR___stack_chk_guard_006a9ae8;
  if (piVar10 == (int *)0x0) {
    if (uVar8 == 0) {
      uVar5 = 1;
      *pppppcStack_a0 = (char ****)((int)ppppcStack_160 + (int)ptag);
      goto LAB_0055e8b0;
    }
    if (0 < (int)ptag) goto LAB_0055e6e0;
  }
  else {
    if (0 < (int)ptag) {
LAB_0055e6e0:
      bVar1 = 4 < (int)in_stack_fffffef0;
LAB_0055e740:
      do {
        ppppcVar3 = ppppcStack_160;
        if (((ptag != (char *****)0x1) && (*(char *)ppppcStack_160 == '\0')) &&
           (*(char *)((int)ppppcStack_160 + 1) == '\0')) {
          ppppcStack_160 = (char ****)((int)ppppcStack_160 + 2);
          if (uVar8 != 0) goto LAB_0055e914;
          uVar12 = 0x9f;
          uVar7 = 0x435;
          goto LAB_0055e838;
        }
        ppppcStack_150 = ppppcStack_160;
        uVar6 = ASN1_get_object((uchar **)&ppppcStack_150,&iStack_154,&iStack_15c,&iStack_158,
                                (long)ptag);
        uVar5 = uVar6 & 0x80;
        if (uVar5 != 0) {
          uVar5 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x68,0x66,s_tasn_dec_c_0066a0bc,0x4a3);
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x6a,0x3a,s_tasn_dec_c_0066a0bc,0x43e);
          goto LAB_0055e8b0;
        }
        ppppcStack_160 = ppppcStack_150;
        iVar4 = iStack_154;
        if ((uVar6 & 1) != 0) {
          iVar4 = (int)ptag - ((int)ppppcStack_150 - (int)ppppcVar3);
        }
        if ((uVar6 & 0x20) == 0) {
          if (iVar4 != 0) {
            if (piVar10 != (int *)0x0) {
              iVar9 = *piVar10;
              uVar5 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(piVar10,iVar9 + iVar4);
              if (uVar5 == 0) {
                (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x8c,0x41,s_tasn_dec_c_0066a0bc,0x45c);
                goto LAB_0055e8b0;
              }
              (*(code *)PTR_memcpy_006a9aec)(piVar10[1] + iVar9,ppppcStack_160,iVar4);
            }
            ppppcStack_160 = (char ****)((int)ppppcStack_160 + iVar4);
            ptag = (char *****)((int)ptag - ((int)ppppcStack_160 - (int)ppppcVar3));
            if ((int)ptag < 1) break;
            goto LAB_0055e740;
          }
        }
        else {
          if (bVar1) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x6a,0xc5,s_tasn_dec_c_0066a0bc,0x445);
            goto LAB_0055e8b0;
          }
          uVar5 = asn1_collect_constprop_0
                            (piVar10,&ppppcStack_160,iVar4,(byte)uVar6 & 1,
                             (undefined *)((int)in_stack_fffffef0 + 1));
          if (uVar5 == 0) goto LAB_0055e8b0;
        }
        ptag = (char *****)((int)ptag - ((int)ppppcStack_160 - (int)ppppcVar3));
      } while (0 < (int)ptag);
    }
    if (uVar8 == 0) {
LAB_0055e914:
      uVar5 = 1;
      *pppppcStack_a0 = ppppcStack_160;
      goto LAB_0055e8b0;
    }
  }
  uVar12 = 0x89;
  uVar7 = 0x44f;
LAB_0055e838:
  uVar5 = 0;
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x6a,uVar12,s_tasn_dec_c_0066a0bc,uVar7);
LAB_0055e8b0:
  if (uStack_14c == *(uint *)puVar2) {
    return uVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (0x1e < uStack_14c) {
    return 0;
  }
  return *(int *)(tag2bit + uStack_14c * 4);
}

