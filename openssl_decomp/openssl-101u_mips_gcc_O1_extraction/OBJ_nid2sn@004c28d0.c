
char * OBJ_nid2sn(int n)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  char *pcVar4;
  int iVar5;
  void *ptr;
  int *piVar6;
  int iVar7;
  undefined *puVar8;
  undefined4 *in_a1;
  undefined4 *puVar9;
  ASN1_OBJECT *in_a2;
  char *in_a3;
  byte *pbVar10;
  char *pcVar11;
  int unaff_s1;
  int unaff_s2;
  int unaff_s4;
  uint uVar12;
  ASN1_OBJECT *unaff_s5;
  uint uVar13;
  undefined1 *unaff_s6;
  undefined1 *unaff_s7;
  code *pcVar14;
  undefined *puVar15;
  char *unaff_s8;
  byte *pbVar16;
  char *pcStack_174;
  char *pcStack_170;
  undefined4 uStack_160;
  undefined *puStack_15c;
  undefined auStack_158 [8];
  uint uStack_150;
  undefined auStack_140 [28];
  int iStack_124;
  char *pcStack_120;
  int iStack_11c;
  int iStack_118;
  undefined *puStack_114;
  int iStack_110;
  ASN1_OBJECT *pAStack_10c;
  undefined1 *puStack_108;
  undefined1 *puStack_104;
  char *pcStack_100;
  code *pcStack_fc;
  undefined4 *puStack_f4;
  undefined *puStack_e8;
  char *pcStack_dc;
  undefined4 uStack_d4;
  int iStack_d0;
  char *pcStack_cc;
  undefined *puStack_c8;
  undefined4 uStack_7c;
  undefined *puStack_78;
  undefined auStack_74 [8];
  uint uStack_6c;
  int iStack_5c;
  undefined *puStack_58;
  code *pcStack_54;
  undefined4 local_40;
  undefined *local_38;
  undefined4 local_2c;
  undefined *local_28;
  undefined auStack_24 [8];
  int local_1c;
  uint local_c;
  
  puStack_58 = PTR___stack_chk_guard_006a9ae8;
  local_38 = &_gp;
  local_c = *(uint *)PTR___stack_chk_guard_006a9ae8;
  if ((uint)n < 0x398) {
    if (n == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = n * 8;
      in_a1 = *(undefined4 **)(nid_objs + n * 0x18 + 8);
      in_a3 = "TBEX";
      n = n * 0x20;
      if (in_a1 == (undefined4 *)0x0) {
        local_40 = 0x15b;
        pcVar14 = (code *)PTR_ERR_put_error_006a7f34;
LAB_004c29b8:
        in_a3 = "obj_dat.c";
        in_a2 = (ASN1_OBJECT *)&DAT_00000065;
        in_a1 = (undefined4 *)&DAT_00000068;
        (*pcVar14)(8);
        pcVar4 = (char *)0x0;
        goto LAB_004c2978;
      }
    }
    pcVar4 = *(char **)(nid_objs + (n - iVar7));
  }
  else if (added == 0) {
    pcVar4 = (char *)0x0;
  }
  else {
    in_a1 = &local_2c;
    local_2c = 3;
    local_28 = auStack_24;
    local_1c = n;
    iVar7 = (*(code *)PTR_lh_retrieve_006a73b0)(added);
    if (iVar7 == 0) {
      pcVar14 = *(code **)(local_38 + -0x6eac);
      local_40 = 0x169;
      goto LAB_004c29b8;
    }
    pcVar4 = **(char ***)(iVar7 + 4);
  }
LAB_004c2978:
  if (local_c == *(uint *)puStack_58) {
    return pcVar4;
  }
  pcStack_54 = OBJ_nid2ln;
  uVar13 = local_c;
  (**(code **)(local_38 + -0x5330))();
  pcStack_120 = PTR___stack_chk_guard_006a9ae8;
  iStack_5c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (uVar13 < 0x398) {
    if (uVar13 == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = uVar13 * 8;
      in_a1 = *(undefined4 **)(nid_objs + uVar13 * 0x18 + 8);
      in_a3 = "TBEX";
      uVar13 = uVar13 * 0x20;
      if (in_a1 == (undefined4 *)0x0) {
LAB_004c2ae0:
        in_a3 = "obj_dat.c";
        in_a2 = (ASN1_OBJECT *)&DAT_00000065;
        in_a1 = (undefined4 *)0x66;
        (*(code *)PTR_ERR_put_error_006a7f34)(8);
        pcVar4 = (char *)0x0;
        goto LAB_004c2aa0;
      }
    }
    pcVar4 = *(char **)(nid_objs + (uVar13 - iVar7) + 4);
  }
  else if (added == 0) {
    pcVar4 = (char *)0x0;
  }
  else {
    in_a1 = &uStack_7c;
    uStack_7c = 3;
    puStack_78 = auStack_74;
    uStack_6c = uVar13;
    iVar7 = (*(code *)PTR_lh_retrieve_006a73b0)(added);
    if (iVar7 == 0) goto LAB_004c2ae0;
    pcVar4 = *(char **)(*(int *)(iVar7 + 4) + 4);
  }
LAB_004c2aa0:
  if (iStack_5c == *(int *)pcStack_120) {
    return pcVar4;
  }
  iVar7 = iStack_5c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_114 = PTR___stack_chk_guard_006a9ae8;
  puStack_c8 = pcStack_120;
  puStack_e8 = &_gp;
  pcStack_cc = *(char **)PTR___stack_chk_guard_006a9ae8;
  pcVar4 = (char *)0x0;
  iStack_118 = unaff_s2;
  puVar15 = &_gp;
  if ((iVar7 != 0) && (pcVar4 = *(char **)(iVar7 + 8), iStack_118 = iVar7, pcVar4 == (char *)0x0)) {
    unaff_s5 = *(ASN1_OBJECT **)(iVar7 + 0xc);
    pcVar4 = (char *)0x0;
    if (unaff_s5 != (ASN1_OBJECT *)0x0) {
      if (added == 0) {
LAB_004c2bfc:
        unaff_s8 = (char *)0x0;
        unaff_s7 = obj_objs;
        unaff_s6 = nid_objs;
        pcStack_120 = (char *)0x359;
        pcVar4 = (char *)0x359;
        puVar15 = puStack_e8;
        do {
          pcVar11 = (char *)((int)pcStack_120 >> 1);
          iVar5 = *(int *)(obj_objs + (int)pcVar11 * 4);
          unaff_s4 = iVar5 * 8;
          unaff_s1 = iVar5 * 0x20;
          if (unaff_s5 == *(ASN1_OBJECT **)(nid_objs + iVar5 * 0x18 + 0xc)) {
            in_a1 = *(undefined4 **)(nid_objs + iVar5 * 0x18 + 0x10);
            in_a2 = unaff_s5;
            pcStack_dc = pcVar4;
            iVar5 = (**(code **)(puVar15 + -0x5310))(*(undefined4 *)(iVar7 + 0x10));
            puVar15 = puStack_e8;
            if (-1 < iVar5) {
              puVar9 = in_a1;
              in_a3 = pcStack_dc;
              pcVar4 = pcStack_dc;
              pcStack_120 = pcVar11;
              if (iVar5 == 0) goto LAB_004c2cf8;
LAB_004c2c6c:
              unaff_s8 = pcVar11 + 1;
              pcVar11 = pcVar4;
            }
          }
          else if (-1 < (int)unaff_s5 - (int)*(ASN1_OBJECT **)(nid_objs + iVar5 * 0x18 + 0xc))
          goto LAB_004c2c6c;
          pcStack_120 = pcVar11 + (int)unaff_s8;
          pcVar4 = pcVar11;
        } while ((int)unaff_s8 < (int)pcVar11);
        pcVar4 = (char *)0x0;
        in_a3 = pcVar11;
      }
      else {
        in_a1 = &uStack_d4;
        uStack_d4 = 0;
        iStack_d0 = iVar7;
        iVar5 = (*(code *)PTR_lh_retrieve_006a73b0)();
        puVar15 = puStack_e8;
        if (iVar5 == 0) {
          unaff_s5 = *(ASN1_OBJECT **)(iVar7 + 0xc);
          if (unaff_s5 != (ASN1_OBJECT *)0x0) goto LAB_004c2bfc;
          puVar8 = (undefined *)0x0;
          unaff_s7 = obj_objs;
          unaff_s6 = nid_objs;
          puVar9 = (undefined4 *)0x359;
          do {
            in_a1 = (undefined4 *)((int)(puVar8 + (int)puVar9) >> 1);
            iVar7 = *(int *)(obj_objs + (int)in_a1 * 4);
            unaff_s4 = iVar7 * 8;
            unaff_s1 = iVar7 * 0x20;
            if (*(int *)(nid_objs + iVar7 * 0x18 + 0xc) == 0) goto LAB_004c2cf8;
            if (*(int *)(nid_objs + iVar7 * 0x18 + 0xc) < 1) {
              puVar8 = (undefined *)((int)in_a1 + 1);
              in_a1 = puVar9;
            }
            pcVar4 = (char *)0x0;
            puVar9 = in_a1;
          } while ((int)puVar8 < (int)in_a1);
        }
        else {
          pcVar4 = *(char **)(*(int *)(iVar5 + 4) + 8);
        }
      }
    }
  }
  goto LAB_004c2bb4;
LAB_004c2cf8:
  in_a1 = puVar9;
  unaff_s7 = obj_objs;
  unaff_s6 = nid_objs;
  pcVar4 = *(char **)(nid_objs + (unaff_s1 - unaff_s4) + 8);
  puVar15 = puStack_e8;
LAB_004c2bb4:
  if (pcStack_cc == *(char **)puStack_114) {
    return pcVar4;
  }
  pcStack_fc = OBJ_obj2txt;
  pcStack_174 = pcStack_cc;
  (**(code **)(puVar15 + -0x5330))();
  puVar15 = PTR___stack_chk_guard_006a9ae8;
  iStack_124 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((pcStack_174 != (char *)0x0) && (0 < (int)in_a1)) {
    *pcStack_174 = '\0';
  }
  pcStack_170 = (char *)0x0;
  iStack_11c = unaff_s1;
  iStack_110 = unaff_s4;
  pAStack_10c = unaff_s5;
  puStack_108 = unaff_s6;
  puStack_104 = unaff_s7;
  pcStack_100 = unaff_s8;
  puStack_f4 = in_a1;
  if (in_a2 == (ASN1_OBJECT *)0x0) goto LAB_004c2e70;
  pbVar10 = in_a2->data;
  if (pbVar10 == (byte *)0x0) goto LAB_004c2e70;
  if (in_a3 != (char *)0x0) goto LAB_004c2da0;
  uVar13 = OBJ_obj2nid(in_a2);
  if (uVar13 == 0) {
LAB_004c3128:
    pbVar10 = in_a2->data;
  }
  else {
    if (uVar13 < 0x398) {
      iVar7 = uVar13 * 0x18;
      piVar6 = (int *)(nid_objs + iVar7);
      pcVar14 = (code *)PTR_ERR_put_error_006a7f34;
      if (*(int *)(nid_objs + iVar7 + 8) == 0) goto LAB_004c32f8;
      iVar7 = *(int *)(nid_objs + iVar7 + 4);
      if (iVar7 != 0) goto LAB_004c31bc;
    }
    else {
      if (added != 0) {
        uStack_160 = 3;
        puStack_15c = auStack_158;
        uStack_150 = uVar13;
        iVar7 = (*(code *)PTR_lh_retrieve_006a73b0)(added,&uStack_160);
        if (iVar7 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(8,0x66,0x65,"obj_dat.c",0x184);
        }
        else {
          iVar7 = *(int *)(*(int *)(iVar7 + 4) + 4);
          if (iVar7 != 0) goto LAB_004c31bc;
        }
      }
      if (added == 0) goto LAB_004c3128;
      uStack_160 = 3;
      puStack_15c = auStack_158;
      uStack_150 = uVar13;
      iVar7 = (*(code *)PTR_lh_retrieve_006a73b0)(added,&uStack_160);
      if (iVar7 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(8,0x68,0x65,"obj_dat.c",0x169);
        pbVar10 = in_a2->data;
        goto LAB_004c2da0;
      }
      piVar6 = *(int **)(iVar7 + 4);
    }
    iVar7 = *piVar6;
    if (iVar7 != 0) {
LAB_004c31bc:
      if (pcStack_174 != (char *)0x0) {
        (*(code *)PTR_BUF_strlcpy_006a6f64)(pcStack_174,iVar7,puStack_f4);
      }
      pcStack_170 = (char *)(*(code *)PTR_strlen_006a9a24)(iVar7);
      goto LAB_004c2e70;
    }
    pbVar10 = in_a2->data;
  }
LAB_004c2da0:
  iVar7 = in_a2->length;
  pcStack_170 = (char *)0x0;
  if (0 < iVar7) {
    pcStack_170 = (char *)0x0;
    bVar3 = true;
    in_a2 = (ASN1_OBJECT *)0x0;
LAB_004c2dd4:
    uVar13 = 0;
    bVar2 = false;
    pbVar16 = pbVar10;
LAB_004c2de0:
    do {
      pbVar10 = pbVar16 + 1;
      iVar7 = iVar7 + -1;
      bVar1 = *pbVar16;
      uVar12 = (uint)bVar1;
      pbVar16 = pbVar10;
      if (iVar7 == 0) {
        if ((char)bVar1 < '\0') goto LAB_004c2e50;
        if (!bVar2) {
          uVar13 = uVar13 | uVar12;
LAB_004c3020:
          if (!bVar3) goto LAB_004c3028;
          bVar2 = false;
          if (0x4f < uVar13) goto LAB_004c31ec;
          goto LAB_004c30d4;
        }
LAB_004c2eb8:
        iVar5 = (*(code *)PTR_BN_add_word_006a70bc)(in_a2,uVar12 & 0x7f);
        if (iVar5 == 0) goto LAB_004c2e50;
        if (-1 < (char)bVar1) goto code_r0x004c2ed8;
      }
      else {
        if (bVar2) goto LAB_004c2eb8;
        uVar13 = uVar13 | uVar12 & 0x7f;
        if (-1 < (char)bVar1) goto LAB_004c3020;
        if (uVar13 < 0x2000000) {
          uVar13 = uVar13 << 7;
          goto LAB_004c2de0;
        }
        if ((in_a2 == (ASN1_OBJECT *)0x0) &&
           (in_a2 = (ASN1_OBJECT *)(*(code *)PTR_BN_new_006a71b4)(), in_a2 == (ASN1_OBJECT *)0x0)) {
          pcStack_170 = (char *)0xffffffff;
          break;
        }
        iVar5 = (*(code *)PTR_BN_set_word_006a7730)(in_a2,uVar13);
        if (iVar5 == 0) goto LAB_004c2e58;
        bVar2 = true;
      }
      iVar5 = (*(code *)PTR_BN_lshift_006a8498)(in_a2,in_a2,7);
      if (iVar5 == 0) goto LAB_004c2e50;
    } while( true );
  }
  goto LAB_004c2e70;
code_r0x004c2ed8:
  if (bVar3) {
    if (uVar13 < 0x50) {
LAB_004c30d4:
      uVar12 = uVar13 / 0x28;
      uVar13 = uVar13 - (uVar12 * 8 + ((uint)((ulonglong)uVar13 * 0xcccccccd >> 0x20) & 0xffffffe0))
      ;
    }
    else if (bVar2) {
      iVar5 = (*(code *)PTR_BN_sub_word_006a849c)(in_a2,0x50);
      if (iVar5 == 0) goto LAB_004c2e50;
      uVar12 = 2;
    }
    else {
LAB_004c31ec:
      uVar13 = uVar13 - 0x50;
      uVar12 = 2;
    }
    if ((pcStack_174 != (char *)0x0) && (1 < (int)puStack_f4)) {
      pcStack_174[1] = '\0';
      puStack_f4 = (undefined4 *)((int)puStack_f4 + -1);
      *pcStack_174 = (char)uVar12 + '0';
      pcStack_174 = pcStack_174 + 1;
    }
    pcStack_170 = pcStack_170 + 1;
    if (!bVar2) {
LAB_004c3028:
      (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_140,0x1a,&DAT_0064cf14,uVar13);
      iVar5 = (*(code *)PTR_strlen_006a9a24)(auStack_140);
      if ((pcStack_174 != (char *)0x0) && (0 < (int)puStack_f4)) {
        (*(code *)PTR_BUF_strlcpy_006a6f64)(pcStack_174,auStack_140,puStack_f4);
        puVar9 = puStack_f4;
        if ((int)puStack_f4 < iVar5) {
          puStack_f4 = (undefined4 *)0x0;
          pcStack_174 = pcStack_174 + (int)puVar9;
        }
        else {
          pcStack_174 = pcStack_174 + iVar5;
          puStack_f4 = (undefined4 *)((int)puStack_f4 - iVar5);
        }
      }
      pcStack_170 = pcStack_170 + iVar5;
      goto LAB_004c30a8;
    }
  }
  ptr = (void *)(*(code *)PTR_BN_bn2dec_006a7e38)(in_a2);
  if (ptr == (void *)0x0) {
LAB_004c2e50:
    pcStack_170 = (char *)0xffffffff;
    if (in_a2 != (ASN1_OBJECT *)0x0) {
LAB_004c2e58:
      (*(code *)PTR_BN_free_006a701c)(in_a2);
      pcStack_170 = (char *)0xffffffff;
    }
    goto LAB_004c2e70;
  }
  iVar5 = (*(code *)PTR_strlen_006a9a24)(ptr);
  if (pcStack_174 != (char *)0x0) {
    if (1 < (int)puStack_f4) {
      pcStack_174[1] = '\0';
      puStack_f4 = (undefined4 *)((int)puStack_f4 + -1);
      *pcStack_174 = '.';
      pcStack_174 = pcStack_174 + 1;
    }
    (*(code *)PTR_BUF_strlcpy_006a6f64)(pcStack_174,ptr,puStack_f4);
    puVar9 = puStack_f4;
    if (iVar5 <= (int)puStack_f4) {
      pcStack_174 = pcStack_174 + iVar5;
      puStack_f4 = (undefined4 *)((int)puStack_f4 - iVar5);
      pcStack_170 = pcStack_170 + iVar5 + 1;
      CRYPTO_free(ptr);
      goto LAB_004c30a8;
    }
    puStack_f4 = (undefined4 *)0x0;
    pcStack_174 = pcStack_174 + (int)puVar9;
  }
  pcStack_170 = pcStack_170 + iVar5 + 1;
  CRYPTO_free(ptr);
LAB_004c30a8:
  bVar3 = false;
  if (iVar7 < 1) goto code_r0x004c30b0;
  goto LAB_004c2dd4;
code_r0x004c30b0:
  if (in_a2 != (ASN1_OBJECT *)0x0) {
    (*(code *)PTR_BN_free_006a701c)(in_a2);
  }
LAB_004c2e70:
  if (iStack_124 == *(int *)puVar15) {
    return pcStack_170;
  }
  pcVar14 = (code *)PTR___stack_chk_fail_006a9ab0;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004c32f8:
  (*pcVar14)(8,0x66,0x65,"obj_dat.c",0x176);
  (*(code *)PTR_ERR_put_error_006a7f34)(8,0x68,0x65,"obj_dat.c",0x15b);
  pbVar10 = in_a2->data;
  goto LAB_004c2da0;
}

