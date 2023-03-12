
char * OBJ_nid2sn(int n)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 *puVar4;
  ASN1_OBJECT *pAVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  void *ptr;
  int *piVar9;
  int iVar10;
  undefined4 *in_a1;
  ASN1_OBJECT *in_a2;
  char *in_a3;
  byte *pbVar11;
  int unaff_s1;
  undefined1 *unaff_s3;
  undefined1 *unaff_s4;
  int unaff_s5;
  uint uVar12;
  int unaff_s6;
  int iVar13;
  uint uVar14;
  int unaff_s7;
  code *pcVar15;
  undefined *puVar16;
  ASN1_OBJECT *unaff_s8;
  byte *pbVar17;
  char *pcStack_16c;
  char *pcStack_168;
  undefined4 uStack_158;
  undefined *puStack_154;
  undefined auStack_150 [8];
  uint uStack_148;
  undefined auStack_138 [28];
  int iStack_11c;
  ASN1_OBJECT *pAStack_118;
  int iStack_114;
  undefined *puStack_110;
  undefined1 *puStack_10c;
  undefined1 *puStack_108;
  int iStack_104;
  int iStack_100;
  int iStack_fc;
  ASN1_OBJECT *pAStack_f8;
  code *pcStack_f4;
  undefined4 *puStack_ec;
  undefined *puStack_e0;
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
  
  puStack_58 = PTR___stack_chk_guard_006aabf0;
  local_38 = &_gp;
  local_c = *(uint *)PTR___stack_chk_guard_006aabf0;
  if ((uint)n < 0x398) {
    if (n == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = n * 8;
      in_a1 = *(undefined4 **)(nid_objs + n * 0x18 + 8);
      in_a3 = "Number";
      n = n * 0x20;
      if (in_a1 == (undefined4 *)0x0) {
        local_40 = 0x14a;
        pcVar15 = (code *)PTR_ERR_put_error_006a9030;
LAB_004c5bb8:
        in_a3 = "obj_dat.c";
        in_a2 = (ASN1_OBJECT *)&DAT_00000065;
        in_a1 = (undefined4 *)&DAT_00000068;
        (*pcVar15)(8);
        pcVar6 = (char *)0x0;
        goto LAB_004c5b78;
      }
    }
    pcVar6 = *(char **)(nid_objs + (n - iVar10));
  }
  else if (added == 0) {
    pcVar6 = (char *)0x0;
  }
  else {
    in_a1 = &local_2c;
    local_2c = 3;
    local_28 = auStack_24;
    local_1c = n;
    iVar10 = (*(code *)PTR_lh_retrieve_006a84b0)(added);
    if (iVar10 == 0) {
      pcVar15 = *(code **)(local_38 + -0x6eb0);
      local_40 = 0x15b;
      goto LAB_004c5bb8;
    }
    pcVar6 = **(char ***)(iVar10 + 4);
  }
LAB_004c5b78:
  if (local_c == *(uint *)puStack_58) {
    return pcVar6;
  }
  pcStack_54 = OBJ_nid2ln;
  uVar14 = local_c;
  (**(code **)(local_38 + -0x5328))();
  pAStack_118 = (ASN1_OBJECT *)PTR___stack_chk_guard_006aabf0;
  iStack_5c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (uVar14 < 0x398) {
    if (uVar14 == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = uVar14 * 8;
      in_a1 = *(undefined4 **)(nid_objs + uVar14 * 0x18 + 8);
      in_a3 = "Number";
      uVar14 = uVar14 * 0x20;
      if (in_a1 == (undefined4 *)0x0) {
LAB_004c5ce0:
        in_a3 = "obj_dat.c";
        in_a2 = (ASN1_OBJECT *)&DAT_00000065;
        in_a1 = (undefined4 *)0x66;
        (*(code *)PTR_ERR_put_error_006a9030)(8);
        pcVar6 = (char *)0x0;
        goto LAB_004c5ca0;
      }
    }
    pcVar6 = *(char **)(nid_objs + (uVar14 - iVar10) + 4);
  }
  else if (added == 0) {
    pcVar6 = (char *)0x0;
  }
  else {
    in_a1 = &uStack_7c;
    uStack_7c = 3;
    puStack_78 = auStack_74;
    uStack_6c = uVar14;
    iVar10 = (*(code *)PTR_lh_retrieve_006a84b0)(added);
    if (iVar10 == 0) goto LAB_004c5ce0;
    pcVar6 = *(char **)(*(int *)(iVar10 + 4) + 4);
  }
LAB_004c5ca0:
  if (iStack_5c == *(int *)pAStack_118) {
    return pcVar6;
  }
  iVar10 = iStack_5c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_110 = PTR___stack_chk_guard_006aabf0;
  puStack_c8 = (undefined *)pAStack_118;
  puStack_e0 = &_gp;
  pcStack_cc = *(char **)PTR___stack_chk_guard_006aabf0;
  pcVar6 = (char *)0x0;
  iStack_100 = unaff_s6;
  iStack_fc = unaff_s7;
  puVar16 = &_gp;
  if ((iVar10 != 0) && (pcVar6 = *(char **)(iVar10 + 8), iStack_fc = iVar10, pcVar6 == (char *)0x0))
  {
    if (added != 0) {
      in_a1 = &uStack_d4;
      uStack_d4 = 0;
      iStack_d0 = iVar10;
      iVar7 = (*(code *)PTR_lh_retrieve_006a84b0)();
      if (iVar7 != 0) {
        pcVar6 = *(char **)(*(int *)(iVar7 + 4) + 8);
        puVar16 = puStack_e0;
        goto LAB_004c5da8;
      }
    }
    unaff_s8 = *(ASN1_OBJECT **)(iVar10 + 0xc);
    unaff_s5 = 0;
    unaff_s4 = obj_objs;
    unaff_s3 = nid_objs;
    unaff_s1 = 0x359;
    iStack_100 = 0x359;
    puVar16 = puStack_e0;
    do {
      unaff_s1 = unaff_s1 >> 1;
      iVar7 = *(int *)(obj_objs + unaff_s1 * 4) * 0x18;
      pAStack_118 = (ASN1_OBJECT *)(nid_objs + iVar7);
      iVar13 = unaff_s1;
      if (unaff_s8 == *(ASN1_OBJECT **)(nid_objs + iVar7 + 0xc)) {
        in_a1 = *(undefined4 **)(nid_objs + iVar7 + 0x10);
        in_a2 = unaff_s8;
        iVar8 = (**(code **)(puVar16 + -0x5308))(*(undefined4 *)(iVar10 + 0x10));
        puVar16 = puStack_e0;
        if (-1 < iVar8) {
          if (iVar8 == 0) {
            pcVar6 = *(char **)(nid_objs + iVar7 + 8);
            goto LAB_004c5da8;
          }
LAB_004c5e54:
          unaff_s5 = unaff_s1 + 1;
          iVar13 = iStack_100;
        }
      }
      else if (-1 < (int)unaff_s8 - (int)*(ASN1_OBJECT **)(nid_objs + iVar7 + 0xc))
      goto LAB_004c5e54;
      unaff_s1 = iVar13 + unaff_s5;
      iStack_100 = iVar13;
    } while (unaff_s5 < iVar13);
    pcVar6 = (char *)0x0;
  }
LAB_004c5da8:
  if (pcStack_cc == *(char **)puStack_110) {
    return pcVar6;
  }
  pcStack_f4 = OBJ_obj2txt;
  pcStack_16c = pcStack_cc;
  (**(code **)(puVar16 + -0x5328))();
  puVar16 = PTR___stack_chk_guard_006aabf0;
  iStack_11c = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar5 = pAStack_118;
  iStack_114 = unaff_s1;
  puStack_10c = unaff_s3;
  puStack_108 = unaff_s4;
  iStack_104 = unaff_s5;
  pAStack_f8 = unaff_s8;
  puStack_ec = in_a1;
  if ((in_a2 == (ASN1_OBJECT *)0x0) ||
     (pbVar11 = in_a2->data, pAVar5 = in_a2, pbVar11 == (byte *)0x0)) {
    in_a2 = pAVar5;
    *pcStack_16c = '\0';
    pcStack_168 = (char *)0x0;
    goto LAB_004c5fc8;
  }
  if (in_a3 != (char *)0x0) goto LAB_004c5efc;
  uVar14 = OBJ_obj2nid(in_a2);
  if (uVar14 == 0) {
LAB_004c6274:
    pbVar11 = in_a2->data;
  }
  else {
    if (uVar14 < 0x398) {
      iVar10 = uVar14 * 0x18;
      piVar9 = (int *)(nid_objs + iVar10);
      pcVar15 = (code *)PTR_ERR_put_error_006a9030;
      if (*(int *)(nid_objs + iVar10 + 8) == 0) goto LAB_004c6454;
      iVar10 = *(int *)(nid_objs + iVar10 + 4);
      if (iVar10 != 0) goto LAB_004c6304;
    }
    else {
      if (added != 0) {
        uStack_158 = 3;
        puStack_154 = auStack_150;
        uStack_148 = uVar14;
        iVar10 = (*(code *)PTR_lh_retrieve_006a84b0)(added,&uStack_158);
        if (iVar10 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(8,0x66,0x65,"obj_dat.c",0x17b);
        }
        else {
          iVar10 = *(int *)(*(int *)(iVar10 + 4) + 4);
          if (iVar10 != 0) goto LAB_004c6304;
        }
      }
      if (added == 0) goto LAB_004c6274;
      uStack_158 = 3;
      puStack_154 = auStack_150;
      uStack_148 = uVar14;
      iVar10 = (*(code *)PTR_lh_retrieve_006a84b0)(added,&uStack_158);
      if (iVar10 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(8,0x68,0x65,"obj_dat.c",0x15b);
        pbVar11 = in_a2->data;
        goto LAB_004c5efc;
      }
      piVar9 = *(int **)(iVar10 + 4);
    }
    iVar10 = *piVar9;
    if (iVar10 != 0) {
LAB_004c6304:
      if (pcStack_16c != (char *)0x0) {
        (*(code *)PTR_BUF_strlcpy_006a8064)(pcStack_16c,iVar10,puStack_ec);
      }
      pcStack_168 = (char *)(*(code *)PTR_strlen_006aab30)(iVar10);
      goto LAB_004c5fc8;
    }
    pbVar11 = in_a2->data;
  }
LAB_004c5efc:
  iVar10 = in_a2->length;
  pcStack_168 = (char *)0x0;
  if (0 < iVar10) {
    pcStack_168 = (char *)0x0;
    bVar3 = true;
    in_a2 = (ASN1_OBJECT *)0x0;
LAB_004c5f30:
    uVar14 = 0;
    bVar2 = false;
    pbVar17 = pbVar11;
LAB_004c5f3c:
    do {
      pbVar11 = pbVar17 + 1;
      iVar10 = iVar10 + -1;
      bVar1 = *pbVar17;
      uVar12 = (uint)bVar1;
      pbVar17 = pbVar11;
      if (iVar10 == 0) {
        if ((char)bVar1 < '\0') goto LAB_004c5fac;
        if (!bVar2) {
          uVar14 = uVar14 | uVar12;
LAB_004c616c:
          if (!bVar3) goto LAB_004c6174;
          bVar2 = false;
          if (0x4f < uVar14) goto LAB_004c6348;
          goto LAB_004c6220;
        }
LAB_004c6014:
        iVar7 = (*(code *)PTR_BN_add_word_006a81bc)(in_a2,uVar12 & 0x7f);
        if (iVar7 == 0) goto LAB_004c5fac;
        if (-1 < (char)bVar1) goto code_r0x004c6034;
      }
      else {
        if (bVar2) goto LAB_004c6014;
        uVar14 = uVar14 | uVar12 & 0x7f;
        if (-1 < (char)bVar1) goto LAB_004c616c;
        if (uVar14 < 0x2000000) {
          uVar14 = uVar14 << 7;
          goto LAB_004c5f3c;
        }
        if ((in_a2 == (ASN1_OBJECT *)0x0) &&
           (in_a2 = (ASN1_OBJECT *)(*(code *)PTR_BN_new_006a82b4)(), in_a2 == (ASN1_OBJECT *)0x0)) {
          pcStack_168 = (char *)0xffffffff;
          break;
        }
        iVar7 = (*(code *)PTR_BN_set_word_006a8820)(in_a2,uVar14);
        if (iVar7 == 0) goto LAB_004c5fb4;
        bVar2 = true;
      }
      iVar7 = (*(code *)PTR_BN_lshift_006a95b8)(in_a2,in_a2,7);
      if (iVar7 == 0) goto LAB_004c5fac;
    } while( true );
  }
  goto LAB_004c5fc8;
code_r0x004c6034:
  if (bVar3) {
    if (uVar14 < 0x50) {
LAB_004c6220:
      uVar12 = uVar14 / 0x28;
      uVar14 = uVar14 - (uVar12 * 8 + ((uint)((ulonglong)uVar14 * 0xcccccccd >> 0x20) & 0xffffffe0))
      ;
    }
    else if (bVar2) {
      iVar7 = (*(code *)PTR_BN_sub_word_006a95bc)(in_a2,0x50);
      if (iVar7 == 0) goto LAB_004c5fac;
      uVar12 = 2;
    }
    else {
LAB_004c6348:
      uVar14 = uVar14 - 0x50;
      uVar12 = 2;
    }
    if ((pcStack_16c != (char *)0x0) && (0 < (int)puStack_ec)) {
      puStack_ec = (undefined4 *)((int)puStack_ec + -1);
      *pcStack_16c = (char)uVar12 + '0';
      pcStack_16c = pcStack_16c + 1;
    }
    pcStack_168 = pcStack_168 + 1;
    if (!bVar2) {
LAB_004c6174:
      (*(code *)PTR_BIO_snprintf_006a8060)(auStack_138,0x1a,&DAT_0064d898,uVar14);
      iVar7 = (*(code *)PTR_strlen_006aab30)(auStack_138);
      if ((pcStack_16c != (char *)0x0) && (0 < (int)puStack_ec)) {
        (*(code *)PTR_BUF_strlcpy_006a8064)(pcStack_16c,auStack_138,puStack_ec);
        puVar4 = puStack_ec;
        if ((int)puStack_ec < iVar7) {
          puStack_ec = (undefined4 *)0x0;
          pcStack_16c = pcStack_16c + (int)puVar4;
        }
        else {
          pcStack_16c = pcStack_16c + iVar7;
          puStack_ec = (undefined4 *)((int)puStack_ec - iVar7);
        }
      }
      pcStack_168 = pcStack_168 + iVar7;
      goto LAB_004c61f4;
    }
  }
  ptr = (void *)(*(code *)PTR_BN_bn2dec_006a8f28)(in_a2);
  if (ptr == (void *)0x0) {
LAB_004c5fac:
    pcStack_168 = (char *)0xffffffff;
    if (in_a2 != (ASN1_OBJECT *)0x0) {
LAB_004c5fb4:
      (*(code *)PTR_BN_free_006a811c)(in_a2);
      pcStack_168 = (char *)0xffffffff;
    }
    goto LAB_004c5fc8;
  }
  iVar7 = (*(code *)PTR_strlen_006aab30)(ptr);
  if (pcStack_16c != (char *)0x0) {
    if (0 < (int)puStack_ec) {
      puStack_ec = (undefined4 *)((int)puStack_ec + -1);
      *pcStack_16c = '.';
      pcStack_16c = pcStack_16c + 1;
    }
    (*(code *)PTR_BUF_strlcpy_006a8064)(pcStack_16c,ptr,puStack_ec);
    puVar4 = puStack_ec;
    if (iVar7 <= (int)puStack_ec) {
      pcStack_16c = pcStack_16c + iVar7;
      puStack_ec = (undefined4 *)((int)puStack_ec - iVar7);
      pcStack_168 = pcStack_168 + iVar7 + 1;
      CRYPTO_free(ptr);
      goto LAB_004c61f4;
    }
    puStack_ec = (undefined4 *)0x0;
    pcStack_16c = pcStack_16c + (int)puVar4;
  }
  pcStack_168 = pcStack_168 + iVar7 + 1;
  CRYPTO_free(ptr);
LAB_004c61f4:
  bVar3 = false;
  if (iVar10 < 1) goto code_r0x004c61fc;
  goto LAB_004c5f30;
code_r0x004c61fc:
  if (in_a2 != (ASN1_OBJECT *)0x0) {
    (*(code *)PTR_BN_free_006a811c)(in_a2);
  }
LAB_004c5fc8:
  if (iStack_11c == *(int *)puVar16) {
    return pcStack_168;
  }
  pcVar15 = (code *)PTR___stack_chk_fail_006aabb8;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_004c6454:
  (*pcVar15)(8,0x66,0x65,"obj_dat.c",0x16a);
  (*(code *)PTR_ERR_put_error_006a9030)(8,0x68,0x65,"obj_dat.c",0x14a);
  pbVar11 = in_a2->data;
  goto LAB_004c5efc;
}

