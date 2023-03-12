
ASN1_OBJECT * OBJ_nid2obj(int n)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  undefined1 *puVar4;
  ASN1_OBJECT *pAVar5;
  int iVar6;
  void *ptr;
  int *piVar7;
  int iVar8;
  undefined *puVar9;
  undefined4 *in_a1;
  undefined4 *puVar10;
  ASN1_OBJECT *in_a2;
  char *in_a3;
  char *pcVar11;
  byte *pbVar12;
  char *pcVar13;
  int unaff_s1;
  int unaff_s2;
  int unaff_s4;
  uint uVar14;
  ASN1_OBJECT *unaff_s5;
  uint uVar15;
  undefined1 *unaff_s6;
  undefined1 *unaff_s7;
  code *pcVar16;
  undefined *puVar17;
  char *unaff_s8;
  byte *pbVar18;
  char *pcStack_1c4;
  ASN1_OBJECT *pAStack_1c0;
  undefined4 uStack_1b0;
  undefined *puStack_1ac;
  undefined auStack_1a8 [8];
  uint uStack_1a0;
  undefined auStack_190 [28];
  int iStack_174;
  char *pcStack_170;
  int iStack_16c;
  int iStack_168;
  undefined *puStack_164;
  int iStack_160;
  ASN1_OBJECT *pAStack_15c;
  undefined1 *puStack_158;
  undefined1 *puStack_154;
  char *pcStack_150;
  code *pcStack_14c;
  undefined4 *puStack_144;
  undefined *puStack_138;
  char *pcStack_12c;
  undefined4 uStack_124;
  int iStack_120;
  char *pcStack_11c;
  undefined *puStack_118;
  undefined4 uStack_cc;
  undefined *puStack_c8;
  undefined auStack_c4 [8];
  uint uStack_bc;
  int iStack_ac;
  undefined *puStack_a8;
  code *pcStack_a4;
  undefined4 uStack_90;
  undefined *puStack_88;
  undefined4 uStack_7c;
  undefined *puStack_78;
  undefined auStack_74 [8];
  uint uStack_6c;
  uint uStack_5c;
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
      puVar4 = nid_objs;
    }
    else {
      in_a1 = *(undefined4 **)(nid_objs + n * 0x18 + 8);
      if (in_a1 == (undefined4 *)0x0) {
        local_40 = 0x140;
        pcVar16 = (code *)PTR_ERR_put_error_006a7f34;
LAB_004c2890:
        in_a3 = "obj_dat.c";
        in_a2 = (ASN1_OBJECT *)&DAT_00000065;
        in_a1 = (undefined4 *)0x67;
        (*pcVar16)(8);
        puVar4 = (undefined1 *)0x0;
      }
      else {
        puVar4 = nid_objs + n * 0x18;
      }
    }
  }
  else if (added == 0) {
    puVar4 = (undefined1 *)0x0;
  }
  else {
    in_a1 = &local_2c;
    local_2c = 3;
    local_28 = auStack_24;
    local_1c = n;
    iVar8 = (*(code *)PTR_lh_retrieve_006a73b0)(added);
    if (iVar8 == 0) {
      pcVar16 = *(code **)(local_38 + -0x6eac);
      local_40 = 0x14e;
      goto LAB_004c2890;
    }
    puVar4 = *(undefined1 **)(iVar8 + 4);
  }
  if (local_c == *(uint *)puStack_58) {
    return (ASN1_OBJECT *)puVar4;
  }
  pcStack_54 = OBJ_nid2sn;
  uVar15 = local_c;
  (**(code **)(local_38 + -0x5330))();
  puStack_a8 = PTR___stack_chk_guard_006a9ae8;
  puStack_88 = &_gp;
  uStack_5c = *(uint *)PTR___stack_chk_guard_006a9ae8;
  if (uVar15 < 0x398) {
    if (uVar15 == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = uVar15 * 8;
      in_a1 = *(undefined4 **)(nid_objs + uVar15 * 0x18 + 8);
      in_a3 = "TBEX";
      uVar15 = uVar15 * 0x20;
      if (in_a1 == (undefined4 *)0x0) {
        uStack_90 = 0x15b;
        pcVar16 = (code *)PTR_ERR_put_error_006a7f34;
LAB_004c29b8:
        in_a3 = "obj_dat.c";
        in_a2 = (ASN1_OBJECT *)&DAT_00000065;
        in_a1 = (undefined4 *)&DAT_00000068;
        (*pcVar16)(8);
        pAVar5 = (ASN1_OBJECT *)0x0;
        goto LAB_004c2978;
      }
    }
    pAVar5 = *(ASN1_OBJECT **)(nid_objs + (uVar15 - iVar8));
  }
  else if (added == 0) {
    pAVar5 = (ASN1_OBJECT *)0x0;
  }
  else {
    in_a1 = &uStack_7c;
    uStack_7c = 3;
    puStack_78 = auStack_74;
    uStack_6c = uVar15;
    iVar8 = (*(code *)PTR_lh_retrieve_006a73b0)(added);
    if (iVar8 == 0) {
      pcVar16 = *(code **)(puStack_88 + -0x6eac);
      uStack_90 = 0x169;
      goto LAB_004c29b8;
    }
    pAVar5 = **(ASN1_OBJECT ***)(iVar8 + 4);
  }
LAB_004c2978:
  if (uStack_5c == *(uint *)puStack_a8) {
    return pAVar5;
  }
  pcStack_a4 = OBJ_nid2ln;
  uVar15 = uStack_5c;
  (**(code **)(puStack_88 + -0x5330))();
  pcStack_170 = PTR___stack_chk_guard_006a9ae8;
  iStack_ac = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (uVar15 < 0x398) {
    if (uVar15 == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = uVar15 * 8;
      in_a1 = *(undefined4 **)(nid_objs + uVar15 * 0x18 + 8);
      in_a3 = "TBEX";
      uVar15 = uVar15 * 0x20;
      if (in_a1 == (undefined4 *)0x0) {
LAB_004c2ae0:
        in_a3 = "obj_dat.c";
        in_a2 = (ASN1_OBJECT *)&DAT_00000065;
        in_a1 = (undefined4 *)0x66;
        (*(code *)PTR_ERR_put_error_006a7f34)(8);
        pAVar5 = (ASN1_OBJECT *)0x0;
        goto LAB_004c2aa0;
      }
    }
    pAVar5 = *(ASN1_OBJECT **)(nid_objs + (uVar15 - iVar8) + 4);
  }
  else if (added == 0) {
    pAVar5 = (ASN1_OBJECT *)0x0;
  }
  else {
    in_a1 = &uStack_cc;
    uStack_cc = 3;
    puStack_c8 = auStack_c4;
    uStack_bc = uVar15;
    iVar8 = (*(code *)PTR_lh_retrieve_006a73b0)(added);
    if (iVar8 == 0) goto LAB_004c2ae0;
    pAVar5 = *(ASN1_OBJECT **)(*(int *)(iVar8 + 4) + 4);
  }
LAB_004c2aa0:
  if (iStack_ac == *(int *)pcStack_170) {
    return pAVar5;
  }
  iVar8 = iStack_ac;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_164 = PTR___stack_chk_guard_006a9ae8;
  puStack_118 = pcStack_170;
  puStack_138 = &_gp;
  pcStack_11c = *(char **)PTR___stack_chk_guard_006a9ae8;
  pAVar5 = (ASN1_OBJECT *)0x0;
  iStack_168 = unaff_s2;
  puVar17 = &_gp;
  if ((iVar8 != 0) &&
     (pAVar5 = *(ASN1_OBJECT **)(iVar8 + 8), iStack_168 = iVar8, pAVar5 == (ASN1_OBJECT *)0x0)) {
    unaff_s5 = *(ASN1_OBJECT **)(iVar8 + 0xc);
    pAVar5 = (ASN1_OBJECT *)0x0;
    if (unaff_s5 != (ASN1_OBJECT *)0x0) {
      if (added == 0) {
LAB_004c2bfc:
        unaff_s8 = (char *)0x0;
        unaff_s7 = obj_objs;
        unaff_s6 = nid_objs;
        pcStack_170 = (char *)0x359;
        pcVar11 = (char *)0x359;
        puVar17 = puStack_138;
        do {
          pcVar13 = (char *)((int)pcStack_170 >> 1);
          iVar6 = *(int *)(obj_objs + (int)pcVar13 * 4);
          unaff_s4 = iVar6 * 8;
          unaff_s1 = iVar6 * 0x20;
          if (unaff_s5 == *(ASN1_OBJECT **)(nid_objs + iVar6 * 0x18 + 0xc)) {
            in_a1 = *(undefined4 **)(nid_objs + iVar6 * 0x18 + 0x10);
            in_a2 = unaff_s5;
            pcStack_12c = pcVar11;
            iVar6 = (**(code **)(puVar17 + -0x5310))(*(undefined4 *)(iVar8 + 0x10));
            puVar17 = puStack_138;
            if (-1 < iVar6) {
              puVar10 = in_a1;
              in_a3 = pcStack_12c;
              pcVar11 = pcStack_12c;
              pcStack_170 = pcVar13;
              if (iVar6 == 0) goto LAB_004c2cf8;
LAB_004c2c6c:
              unaff_s8 = pcVar13 + 1;
              pcVar13 = pcVar11;
            }
          }
          else if (-1 < (int)unaff_s5 - (int)*(ASN1_OBJECT **)(nid_objs + iVar6 * 0x18 + 0xc))
          goto LAB_004c2c6c;
          pcStack_170 = pcVar13 + (int)unaff_s8;
          pcVar11 = pcVar13;
        } while ((int)unaff_s8 < (int)pcVar13);
        pAVar5 = (ASN1_OBJECT *)0x0;
        in_a3 = pcVar13;
      }
      else {
        in_a1 = &uStack_124;
        uStack_124 = 0;
        iStack_120 = iVar8;
        iVar6 = (*(code *)PTR_lh_retrieve_006a73b0)();
        puVar17 = puStack_138;
        if (iVar6 == 0) {
          unaff_s5 = *(ASN1_OBJECT **)(iVar8 + 0xc);
          if (unaff_s5 != (ASN1_OBJECT *)0x0) goto LAB_004c2bfc;
          puVar9 = (undefined *)0x0;
          unaff_s7 = obj_objs;
          unaff_s6 = nid_objs;
          puVar10 = (undefined4 *)0x359;
          do {
            in_a1 = (undefined4 *)((int)(puVar9 + (int)puVar10) >> 1);
            iVar8 = *(int *)(obj_objs + (int)in_a1 * 4);
            unaff_s4 = iVar8 * 8;
            unaff_s1 = iVar8 * 0x20;
            if (*(int *)(nid_objs + iVar8 * 0x18 + 0xc) == 0) goto LAB_004c2cf8;
            if (*(int *)(nid_objs + iVar8 * 0x18 + 0xc) < 1) {
              puVar9 = (undefined *)((int)in_a1 + 1);
              in_a1 = puVar10;
            }
            pAVar5 = (ASN1_OBJECT *)0x0;
            puVar10 = in_a1;
          } while ((int)puVar9 < (int)in_a1);
        }
        else {
          pAVar5 = *(ASN1_OBJECT **)(*(int *)(iVar6 + 4) + 8);
        }
      }
    }
  }
  goto LAB_004c2bb4;
LAB_004c2cf8:
  in_a1 = puVar10;
  unaff_s7 = obj_objs;
  unaff_s6 = nid_objs;
  pAVar5 = *(ASN1_OBJECT **)(nid_objs + (unaff_s1 - unaff_s4) + 8);
  puVar17 = puStack_138;
LAB_004c2bb4:
  if (pcStack_11c == *(char **)puStack_164) {
    return pAVar5;
  }
  pcStack_14c = OBJ_obj2txt;
  pcStack_1c4 = pcStack_11c;
  (**(code **)(puVar17 + -0x5330))();
  puVar17 = PTR___stack_chk_guard_006a9ae8;
  iStack_174 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((pcStack_1c4 != (char *)0x0) && (0 < (int)in_a1)) {
    *pcStack_1c4 = '\0';
  }
  pAStack_1c0 = (ASN1_OBJECT *)0x0;
  iStack_16c = unaff_s1;
  iStack_160 = unaff_s4;
  pAStack_15c = unaff_s5;
  puStack_158 = unaff_s6;
  puStack_154 = unaff_s7;
  pcStack_150 = unaff_s8;
  puStack_144 = in_a1;
  if (in_a2 == (ASN1_OBJECT *)0x0) goto LAB_004c2e70;
  pbVar12 = in_a2->data;
  if (pbVar12 == (byte *)0x0) goto LAB_004c2e70;
  if (in_a3 != (char *)0x0) goto LAB_004c2da0;
  uVar15 = OBJ_obj2nid(in_a2);
  if (uVar15 == 0) {
LAB_004c3128:
    pbVar12 = in_a2->data;
  }
  else {
    if (uVar15 < 0x398) {
      iVar8 = uVar15 * 0x18;
      piVar7 = (int *)(nid_objs + iVar8);
      pcVar16 = (code *)PTR_ERR_put_error_006a7f34;
      if (*(int *)(nid_objs + iVar8 + 8) == 0) goto LAB_004c32f8;
      iVar8 = *(int *)(nid_objs + iVar8 + 4);
      if (iVar8 != 0) goto LAB_004c31bc;
    }
    else {
      if (added != 0) {
        uStack_1b0 = 3;
        puStack_1ac = auStack_1a8;
        uStack_1a0 = uVar15;
        iVar8 = (*(code *)PTR_lh_retrieve_006a73b0)(added,&uStack_1b0);
        if (iVar8 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(8,0x66,0x65,"obj_dat.c",0x184);
        }
        else {
          iVar8 = *(int *)(*(int *)(iVar8 + 4) + 4);
          if (iVar8 != 0) goto LAB_004c31bc;
        }
      }
      if (added == 0) goto LAB_004c3128;
      uStack_1b0 = 3;
      puStack_1ac = auStack_1a8;
      uStack_1a0 = uVar15;
      iVar8 = (*(code *)PTR_lh_retrieve_006a73b0)(added,&uStack_1b0);
      if (iVar8 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(8,0x68,0x65,"obj_dat.c",0x169);
        pbVar12 = in_a2->data;
        goto LAB_004c2da0;
      }
      piVar7 = *(int **)(iVar8 + 4);
    }
    iVar8 = *piVar7;
    if (iVar8 != 0) {
LAB_004c31bc:
      if (pcStack_1c4 != (char *)0x0) {
        (*(code *)PTR_BUF_strlcpy_006a6f64)(pcStack_1c4,iVar8,puStack_144);
      }
      pAStack_1c0 = (ASN1_OBJECT *)(*(code *)PTR_strlen_006a9a24)(iVar8);
      goto LAB_004c2e70;
    }
    pbVar12 = in_a2->data;
  }
LAB_004c2da0:
  iVar8 = in_a2->length;
  pAStack_1c0 = (ASN1_OBJECT *)0x0;
  if (0 < iVar8) {
    pAStack_1c0 = (ASN1_OBJECT *)0x0;
    bVar3 = true;
    in_a2 = (ASN1_OBJECT *)0x0;
LAB_004c2dd4:
    uVar15 = 0;
    bVar2 = false;
    pbVar18 = pbVar12;
LAB_004c2de0:
    do {
      pbVar12 = pbVar18 + 1;
      iVar8 = iVar8 + -1;
      bVar1 = *pbVar18;
      uVar14 = (uint)bVar1;
      pbVar18 = pbVar12;
      if (iVar8 == 0) {
        if ((char)bVar1 < '\0') goto LAB_004c2e50;
        if (!bVar2) {
          uVar15 = uVar15 | uVar14;
LAB_004c3020:
          if (!bVar3) goto LAB_004c3028;
          bVar2 = false;
          if (0x4f < uVar15) goto LAB_004c31ec;
          goto LAB_004c30d4;
        }
LAB_004c2eb8:
        iVar6 = (*(code *)PTR_BN_add_word_006a70bc)(in_a2,uVar14 & 0x7f);
        if (iVar6 == 0) goto LAB_004c2e50;
        if (-1 < (char)bVar1) goto code_r0x004c2ed8;
      }
      else {
        if (bVar2) goto LAB_004c2eb8;
        uVar15 = uVar15 | uVar14 & 0x7f;
        if (-1 < (char)bVar1) goto LAB_004c3020;
        if (uVar15 < 0x2000000) {
          uVar15 = uVar15 << 7;
          goto LAB_004c2de0;
        }
        if ((in_a2 == (ASN1_OBJECT *)0x0) &&
           (in_a2 = (ASN1_OBJECT *)(*(code *)PTR_BN_new_006a71b4)(), in_a2 == (ASN1_OBJECT *)0x0)) {
          pAStack_1c0 = (ASN1_OBJECT *)0xffffffff;
          break;
        }
        iVar6 = (*(code *)PTR_BN_set_word_006a7730)(in_a2,uVar15);
        if (iVar6 == 0) goto LAB_004c2e58;
        bVar2 = true;
      }
      iVar6 = (*(code *)PTR_BN_lshift_006a8498)(in_a2,in_a2,7);
      if (iVar6 == 0) goto LAB_004c2e50;
    } while( true );
  }
  goto LAB_004c2e70;
code_r0x004c2ed8:
  if (bVar3) {
    if (uVar15 < 0x50) {
LAB_004c30d4:
      uVar14 = uVar15 / 0x28;
      uVar15 = uVar15 - (uVar14 * 8 + ((uint)((ulonglong)uVar15 * 0xcccccccd >> 0x20) & 0xffffffe0))
      ;
    }
    else if (bVar2) {
      iVar6 = (*(code *)PTR_BN_sub_word_006a849c)(in_a2,0x50);
      if (iVar6 == 0) goto LAB_004c2e50;
      uVar14 = 2;
    }
    else {
LAB_004c31ec:
      uVar15 = uVar15 - 0x50;
      uVar14 = 2;
    }
    if ((pcStack_1c4 != (char *)0x0) && (1 < (int)puStack_144)) {
      pcStack_1c4[1] = '\0';
      puStack_144 = (undefined4 *)((int)puStack_144 + -1);
      *pcStack_1c4 = (char)uVar14 + '0';
      pcStack_1c4 = pcStack_1c4 + 1;
    }
    pAStack_1c0 = (ASN1_OBJECT *)((int)&pAStack_1c0->sn + 1);
    if (!bVar2) {
LAB_004c3028:
      (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_190,0x1a,&DAT_0064cf14,uVar15);
      iVar6 = (*(code *)PTR_strlen_006a9a24)(auStack_190);
      if ((pcStack_1c4 != (char *)0x0) && (0 < (int)puStack_144)) {
        (*(code *)PTR_BUF_strlcpy_006a6f64)(pcStack_1c4,auStack_190,puStack_144);
        puVar10 = puStack_144;
        if ((int)puStack_144 < iVar6) {
          puStack_144 = (undefined4 *)0x0;
          pcStack_1c4 = pcStack_1c4 + (int)puVar10;
        }
        else {
          pcStack_1c4 = pcStack_1c4 + iVar6;
          puStack_144 = (undefined4 *)((int)puStack_144 - iVar6);
        }
      }
      pAStack_1c0 = (ASN1_OBJECT *)((int)&pAStack_1c0->sn + iVar6);
      goto LAB_004c30a8;
    }
  }
  ptr = (void *)(*(code *)PTR_BN_bn2dec_006a7e38)(in_a2);
  if (ptr == (void *)0x0) {
LAB_004c2e50:
    pAStack_1c0 = (ASN1_OBJECT *)0xffffffff;
    if (in_a2 != (ASN1_OBJECT *)0x0) {
LAB_004c2e58:
      (*(code *)PTR_BN_free_006a701c)(in_a2);
      pAStack_1c0 = (ASN1_OBJECT *)0xffffffff;
    }
    goto LAB_004c2e70;
  }
  iVar6 = (*(code *)PTR_strlen_006a9a24)(ptr);
  if (pcStack_1c4 != (char *)0x0) {
    if (1 < (int)puStack_144) {
      pcStack_1c4[1] = '\0';
      puStack_144 = (undefined4 *)((int)puStack_144 + -1);
      *pcStack_1c4 = '.';
      pcStack_1c4 = pcStack_1c4 + 1;
    }
    (*(code *)PTR_BUF_strlcpy_006a6f64)(pcStack_1c4,ptr,puStack_144);
    puVar10 = puStack_144;
    if (iVar6 <= (int)puStack_144) {
      pcStack_1c4 = pcStack_1c4 + iVar6;
      puStack_144 = (undefined4 *)((int)puStack_144 - iVar6);
      pAStack_1c0 = (ASN1_OBJECT *)((int)&pAStack_1c0->sn + iVar6 + 1);
      CRYPTO_free(ptr);
      goto LAB_004c30a8;
    }
    puStack_144 = (undefined4 *)0x0;
    pcStack_1c4 = pcStack_1c4 + (int)puVar10;
  }
  pAStack_1c0 = (ASN1_OBJECT *)((int)&pAStack_1c0->sn + iVar6 + 1);
  CRYPTO_free(ptr);
LAB_004c30a8:
  bVar3 = false;
  if (iVar8 < 1) goto code_r0x004c30b0;
  goto LAB_004c2dd4;
code_r0x004c30b0:
  if (in_a2 != (ASN1_OBJECT *)0x0) {
    (*(code *)PTR_BN_free_006a701c)(in_a2);
  }
LAB_004c2e70:
  if (iStack_174 == *(int *)puVar17) {
    return pAStack_1c0;
  }
  pcVar16 = (code *)PTR___stack_chk_fail_006a9ab0;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004c32f8:
  (*pcVar16)(8,0x66,0x65,"obj_dat.c",0x176);
  (*(code *)PTR_ERR_put_error_006a7f34)(8,0x68,0x65,"obj_dat.c",0x15b);
  pbVar12 = in_a2->data;
  goto LAB_004c2da0;
}

