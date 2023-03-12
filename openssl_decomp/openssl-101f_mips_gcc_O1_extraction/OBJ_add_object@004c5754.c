
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int OBJ_add_object(ASN1_OBJECT *obj)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  ASN1_OBJECT **ppAVar4;
  void *pvVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  uchar *puVar11;
  ASN1_OBJECT *in_a2;
  char *in_a3;
  byte *pbVar12;
  ASN1_OBJECT *unaff_s0;
  ASN1_OBJECT *unaff_s1;
  undefined *unaff_s5;
  uint uVar13;
  ASN1_OBJECT *unaff_s6;
  ASN1_OBJECT *pAVar14;
  uint uVar15;
  int unaff_s7;
  code *pcVar16;
  undefined *puVar17;
  ASN1_OBJECT *unaff_s8;
  byte *pbVar18;
  char *pcStack_214;
  int iStack_210;
  undefined4 uStack_200;
  undefined *puStack_1fc;
  undefined auStack_1f8 [8];
  uint uStack_1f0;
  undefined auStack_1e0 [28];
  int iStack_1c4;
  ASN1_OBJECT *pAStack_1c0;
  ASN1_OBJECT *pAStack_1bc;
  undefined *puStack_1b8;
  undefined1 *puStack_1b4;
  undefined1 *puStack_1b0;
  undefined *puStack_1ac;
  ASN1_OBJECT *pAStack_1a8;
  int iStack_1a4;
  ASN1_OBJECT *pAStack_1a0;
  code *pcStack_19c;
  char *pcStack_194;
  undefined *puStack_188;
  ASN1_OBJECT *pAStack_17c;
  int iStack_178;
  char *pcStack_174;
  undefined *puStack_170;
  ASN1_OBJECT *pAStack_16c;
  ASN1_OBJECT *pAStack_168;
  undefined1 *puStack_164;
  undefined *puStack_160;
  undefined *puStack_15c;
  ASN1_OBJECT *pAStack_124;
  undefined *puStack_120;
  undefined auStack_11c [8];
  uint uStack_114;
  int iStack_104;
  undefined *puStack_100;
  code *pcStack_fc;
  undefined4 uStack_e8;
  undefined *puStack_e0;
  ASN1_OBJECT *pAStack_d4;
  undefined *puStack_d0;
  undefined auStack_cc [8];
  uint uStack_c4;
  uint uStack_b4;
  undefined *puStack_b0;
  code *pcStack_ac;
  undefined4 uStack_98;
  undefined *puStack_90;
  ASN1_OBJECT *pAStack_84;
  undefined *puStack_80;
  undefined auStack_7c [8];
  uchar *puStack_74;
  uint uStack_64;
  ASN1_OBJECT *pAStack_60;
  code *pcStack_5c;
  undefined4 local_48;
  undefined *local_40;
  ASN1_OBJECT local_34;
  
  puStack_1b0 = PTR___stack_chk_guard_006aabf0;
  puStack_1b4 = &_ITM_registerTMCloneTable;
  local_40 = &_gp;
  local_34.sn = (char *)0x0;
  local_34.ln = (char **)0x0;
  local_34.nid = 0;
  local_34.length = 0;
  local_34.data = *(uchar **)PTR___stack_chk_guard_006aabf0;
  pcStack_194 = (char *)0x4c0000;
  if (added == 0) {
    pcVar16 = added_obj_LHASH_COMP;
    added = (*(code *)PTR_lh_new_006a850c)(added_obj_LHASH_HASH);
    pcStack_194 = (char *)pcVar16;
    puVar17 = local_40;
    if (added != 0) goto LAB_004c57b0;
LAB_004c5990:
    iVar6 = 0;
  }
  else {
LAB_004c57b0:
    unaff_s1 = OBJ_dup(obj);
    if (unaff_s1 == (ASN1_OBJECT *)0x0) {
LAB_004c5928:
      unaff_s0 = &local_34;
      obj = (ASN1_OBJECT *)&local_34.data;
      puVar17 = local_40;
      do {
        if (unaff_s0->sn != (char *)0x0) {
          CRYPTO_free(unaff_s0->sn);
          puVar17 = local_40;
        }
        unaff_s0 = (ASN1_OBJECT *)&unaff_s0->ln;
      } while (obj != unaff_s0);
      if (unaff_s1 == (ASN1_OBJECT *)0x0) goto LAB_004c5990;
      CRYPTO_free(unaff_s1);
      iVar6 = 0;
      puVar17 = local_40;
    }
    else {
      in_a2 = (ASN1_OBJECT *)0x100;
      pcStack_194 = "obj_dat.c";
      local_34.length = (int)CRYPTO_malloc(8,"obj_dat.c",0x100);
      if ((void *)local_34.length == (void *)0x0) {
LAB_004c5904:
        in_a3 = "obj_dat.c";
        in_a2 = (ASN1_OBJECT *)&DAT_00000041;
        pcStack_194 = &DAT_00000069;
        local_48 = 0x119;
        (**(code **)(local_40 + -0x6eb0))(8);
        goto LAB_004c5928;
      }
      if ((unaff_s1->length != 0) && (obj->data != (uchar *)0x0)) {
        in_a2 = (ASN1_OBJECT *)0x102;
        pcStack_194 = "obj_dat.c";
        local_34.sn = (char *)CRYPTO_malloc(8,"obj_dat.c",0x102);
        if (local_34.sn == (char *)0x0) goto LAB_004c5904;
      }
      if (unaff_s1->sn != (char *)0x0) {
        in_a2 = (ASN1_OBJECT *)0x104;
        pcStack_194 = "obj_dat.c";
        local_34.ln = (char **)CRYPTO_malloc(8,"obj_dat.c",0x104);
        if (local_34.ln == (char **)0x0) goto LAB_004c5904;
      }
      if (unaff_s1->ln != (char **)0x0) {
        in_a2 = (ASN1_OBJECT *)0x106;
        pcStack_194 = "obj_dat.c";
        local_34.nid = (int)CRYPTO_malloc(8,"obj_dat.c",0x106);
        if ((void *)local_34.nid == (void *)0x0) goto LAB_004c5904;
      }
      obj = &local_34;
      unaff_s0 = (ASN1_OBJECT *)0x0;
      unaff_s5 = &SUB_00000004;
      puVar17 = local_40;
      do {
        iVar6 = added;
        ppAVar4 = (ASN1_OBJECT **)obj->sn;
        pcVar16 = *(code **)(puVar17 + -0x79cc);
        if (ppAVar4 != (ASN1_OBJECT **)0x0) {
          *ppAVar4 = unaff_s0;
          ppAVar4[1] = unaff_s1;
          pvVar5 = (void *)(*pcVar16)(iVar6);
          pcStack_194 = (char *)ppAVar4;
          puVar17 = local_40;
          if (pvVar5 != (void *)0x0) {
            CRYPTO_free(pvVar5);
            pcStack_194 = (char *)ppAVar4;
            puVar17 = local_40;
          }
        }
        unaff_s0 = (ASN1_OBJECT *)((int)&unaff_s0->sn + 1);
        obj = (ASN1_OBJECT *)&obj->ln;
      } while (unaff_s0 != (ASN1_OBJECT *)&SUB_00000004);
      iVar6 = unaff_s1->nid;
      unaff_s1->flags = unaff_s1->flags & 0xfffffff2;
    }
  }
  if (local_34.data == *(uchar **)puStack_1b0) {
    return iVar6;
  }
  pcStack_5c = OBJ_nid2obj;
  puVar11 = local_34.data;
  (**(code **)(puVar17 + -0x5328))();
  puStack_b0 = PTR___stack_chk_guard_006aabf0;
  puStack_90 = &_gp;
  uStack_64 = *(uint *)PTR___stack_chk_guard_006aabf0;
  pAStack_60 = unaff_s0;
  if (puVar11 < (uchar *)0x398) {
    if (puVar11 == (uchar *)0x0) {
      puVar7 = nid_objs;
    }
    else {
      pcStack_194 = *(char **)(nid_objs + (int)puVar11 * 0x18 + 8);
      if ((ASN1_OBJECT **)pcStack_194 == (ASN1_OBJECT **)0x0) {
        uStack_98 = 0x12a;
        pcVar16 = (code *)PTR_ERR_put_error_006a9030;
LAB_004c5a90:
        in_a3 = "obj_dat.c";
        in_a2 = (ASN1_OBJECT *)&DAT_00000065;
        pcStack_194 = (char *)0x67;
        (*pcVar16)(8);
        puVar7 = (undefined1 *)0x0;
      }
      else {
        puVar7 = nid_objs + (int)puVar11 * 0x18;
      }
    }
  }
  else if (added == 0) {
    puVar7 = (undefined1 *)0x0;
  }
  else {
    pcStack_194 = (char *)&pAStack_84;
    pAStack_84 = (ASN1_OBJECT *)0x3;
    puStack_80 = auStack_7c;
    puStack_74 = puVar11;
    iVar6 = (*(code *)PTR_lh_retrieve_006a84b0)(added);
    if (iVar6 == 0) {
      pcVar16 = *(code **)(puStack_90 + -0x6eb0);
      uStack_98 = 0x13b;
      goto LAB_004c5a90;
    }
    puVar7 = *(undefined1 **)(iVar6 + 4);
  }
  if (uStack_64 == *(uint *)puStack_b0) {
    return (int)puVar7;
  }
  pcStack_ac = OBJ_nid2sn;
  uVar15 = uStack_64;
  (**(code **)(puStack_90 + -0x5328))();
  puStack_100 = PTR___stack_chk_guard_006aabf0;
  puStack_e0 = &_gp;
  uStack_b4 = *(uint *)PTR___stack_chk_guard_006aabf0;
  if (uVar15 < 0x398) {
    if (uVar15 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = uVar15 * 8;
      pcStack_194 = *(char **)(nid_objs + uVar15 * 0x18 + 8);
      in_a3 = "x";
      uVar15 = uVar15 * 0x20;
      if ((ASN1_OBJECT **)pcStack_194 == (ASN1_OBJECT **)0x0) {
        uStack_e8 = 0x14a;
        pcVar16 = (code *)PTR_ERR_put_error_006a9030;
LAB_004c5bb8:
        in_a3 = "obj_dat.c";
        in_a2 = (ASN1_OBJECT *)&DAT_00000065;
        pcStack_194 = &DAT_00000068;
        (*pcVar16)(8);
        iVar6 = 0;
        goto LAB_004c5b78;
      }
    }
    iVar6 = *(int *)(nid_objs + (uVar15 - iVar6));
  }
  else if (added == 0) {
    iVar6 = 0;
  }
  else {
    pcStack_194 = (char *)&pAStack_d4;
    pAStack_d4 = (ASN1_OBJECT *)0x3;
    puStack_d0 = auStack_cc;
    uStack_c4 = uVar15;
    iVar6 = (*(code *)PTR_lh_retrieve_006a84b0)(added);
    if (iVar6 == 0) {
      pcVar16 = *(code **)(puStack_e0 + -0x6eb0);
      uStack_e8 = 0x15b;
      goto LAB_004c5bb8;
    }
    iVar6 = **(int **)(iVar6 + 4);
  }
LAB_004c5b78:
  if (uStack_b4 == *(uint *)puStack_100) {
    return iVar6;
  }
  pcStack_fc = OBJ_nid2ln;
  uVar15 = uStack_b4;
  (**(code **)(puStack_e0 + -0x5328))();
  pAStack_1c0 = (ASN1_OBJECT *)PTR___stack_chk_guard_006aabf0;
  iStack_104 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (uVar15 < 0x398) {
    if (uVar15 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = uVar15 * 8;
      pcStack_194 = *(char **)(nid_objs + uVar15 * 0x18 + 8);
      in_a3 = "x";
      uVar15 = uVar15 * 0x20;
      if ((ASN1_OBJECT **)pcStack_194 == (ASN1_OBJECT **)0x0) {
LAB_004c5ce0:
        in_a3 = "obj_dat.c";
        in_a2 = (ASN1_OBJECT *)&DAT_00000065;
        pcStack_194 = (char *)0x66;
        (*(code *)PTR_ERR_put_error_006a9030)(8);
        iVar6 = 0;
        goto LAB_004c5ca0;
      }
    }
    iVar6 = *(int *)(nid_objs + (uVar15 - iVar6) + 4);
  }
  else if (added == 0) {
    iVar6 = 0;
  }
  else {
    pcStack_194 = (char *)&pAStack_124;
    pAStack_124 = (ASN1_OBJECT *)0x3;
    puStack_120 = auStack_11c;
    uStack_114 = uVar15;
    iVar6 = (*(code *)PTR_lh_retrieve_006a84b0)(added);
    if (iVar6 == 0) goto LAB_004c5ce0;
    iVar6 = *(int *)(*(int *)(iVar6 + 4) + 4);
  }
LAB_004c5ca0:
  if (iStack_104 == *(int *)pAStack_1c0) {
    return iVar6;
  }
  iVar6 = iStack_104;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_1b8 = PTR___stack_chk_guard_006aabf0;
  puStack_160 = puStack_1b0;
  puStack_164 = &_ITM_registerTMCloneTable;
  puStack_170 = (undefined *)pAStack_1c0;
  puStack_188 = &_gp;
  pcStack_174 = *(char **)PTR___stack_chk_guard_006aabf0;
  iVar8 = 0;
  pAStack_1a8 = unaff_s6;
  iStack_1a4 = unaff_s7;
  puVar17 = &_gp;
  pAStack_16c = unaff_s1;
  pAStack_168 = obj;
  puStack_15c = unaff_s5;
  if ((iVar6 != 0) && (iVar8 = *(int *)(iVar6 + 8), iStack_1a4 = iVar6, iVar8 == 0)) {
    if (added != 0) {
      pcStack_194 = (char *)&pAStack_17c;
      pAStack_17c = (ASN1_OBJECT *)0x0;
      iStack_178 = iVar6;
      iVar8 = (*(code *)PTR_lh_retrieve_006a84b0)();
      if (iVar8 != 0) {
        iVar8 = *(int *)(*(int *)(iVar8 + 4) + 8);
        puVar17 = puStack_188;
        goto LAB_004c5da8;
      }
    }
    unaff_s8 = *(ASN1_OBJECT **)(iVar6 + 0xc);
    unaff_s5 = (undefined *)0x0;
    puStack_1b0 = obj_objs;
    puStack_1b4 = nid_objs;
    unaff_s1 = (ASN1_OBJECT *)0x359;
    pAStack_1a8 = (ASN1_OBJECT *)0x359;
    puVar17 = puStack_188;
    do {
      unaff_s1 = (ASN1_OBJECT *)((int)unaff_s1 >> 1);
      iVar8 = *(int *)(obj_objs + (int)unaff_s1 * 4) * 0x18;
      pAStack_1c0 = (ASN1_OBJECT *)(nid_objs + iVar8);
      pAVar14 = unaff_s1;
      if (unaff_s8 == *(ASN1_OBJECT **)(nid_objs + iVar8 + 0xc)) {
        pcStack_194 = *(char **)(nid_objs + iVar8 + 0x10);
        in_a2 = unaff_s8;
        iVar9 = (**(code **)(puVar17 + -0x5308))(*(undefined4 *)(iVar6 + 0x10));
        puVar17 = puStack_188;
        if (-1 < iVar9) {
          if (iVar9 == 0) {
            iVar8 = *(int *)(nid_objs + iVar8 + 8);
            goto LAB_004c5da8;
          }
LAB_004c5e54:
          unaff_s5 = (undefined *)((int)&unaff_s1->sn + 1);
          pAVar14 = pAStack_1a8;
        }
      }
      else if (-1 < (int)unaff_s8 - (int)*(ASN1_OBJECT **)(nid_objs + iVar8 + 0xc))
      goto LAB_004c5e54;
      unaff_s1 = (ASN1_OBJECT *)(unaff_s5 + (int)&pAVar14->sn);
      pAStack_1a8 = pAVar14;
    } while ((int)unaff_s5 < (int)pAVar14);
    iVar8 = 0;
  }
LAB_004c5da8:
  if (pcStack_174 == *(char **)puStack_1b8) {
    return iVar8;
  }
  pcStack_19c = OBJ_obj2txt;
  pcStack_214 = pcStack_174;
  (**(code **)(puVar17 + -0x5328))();
  puVar17 = PTR___stack_chk_guard_006aabf0;
  iStack_1c4 = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar14 = pAStack_1c0;
  pAStack_1bc = unaff_s1;
  puStack_1ac = unaff_s5;
  pAStack_1a0 = unaff_s8;
  if ((in_a2 == (ASN1_OBJECT *)0x0) ||
     (pbVar12 = in_a2->data, pAVar14 = in_a2, pbVar12 == (byte *)0x0)) {
    in_a2 = pAVar14;
    *pcStack_214 = '\0';
    iStack_210 = 0;
    goto LAB_004c5fc8;
  }
  if (in_a3 != (char *)0x0) goto LAB_004c5efc;
  uVar15 = OBJ_obj2nid(in_a2);
  if (uVar15 == 0) {
LAB_004c6274:
    pbVar12 = in_a2->data;
  }
  else {
    if (uVar15 < 0x398) {
      iVar6 = uVar15 * 0x18;
      piVar10 = (int *)(nid_objs + iVar6);
      pcVar16 = (code *)PTR_ERR_put_error_006a9030;
      if (*(int *)(nid_objs + iVar6 + 8) == 0) goto LAB_004c6454;
      iVar6 = *(int *)(nid_objs + iVar6 + 4);
      if (iVar6 != 0) goto LAB_004c6304;
    }
    else {
      if (added != 0) {
        uStack_200 = 3;
        puStack_1fc = auStack_1f8;
        uStack_1f0 = uVar15;
        iVar6 = (*(code *)PTR_lh_retrieve_006a84b0)(added,&uStack_200);
        if (iVar6 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(8,0x66,0x65,"obj_dat.c",0x17b);
        }
        else {
          iVar6 = *(int *)(*(int *)(iVar6 + 4) + 4);
          if (iVar6 != 0) goto LAB_004c6304;
        }
      }
      if (added == 0) goto LAB_004c6274;
      uStack_200 = 3;
      puStack_1fc = auStack_1f8;
      uStack_1f0 = uVar15;
      iVar6 = (*(code *)PTR_lh_retrieve_006a84b0)(added,&uStack_200);
      if (iVar6 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(8,0x68,0x65,"obj_dat.c",0x15b);
        pbVar12 = in_a2->data;
        goto LAB_004c5efc;
      }
      piVar10 = *(int **)(iVar6 + 4);
    }
    iVar6 = *piVar10;
    if (iVar6 != 0) {
LAB_004c6304:
      if (pcStack_214 != (char *)0x0) {
        (*(code *)PTR_BUF_strlcpy_006a8064)(pcStack_214,iVar6,pcStack_194);
      }
      iStack_210 = (*(code *)PTR_strlen_006aab30)(iVar6);
      goto LAB_004c5fc8;
    }
    pbVar12 = in_a2->data;
  }
LAB_004c5efc:
  iVar6 = in_a2->length;
  iStack_210 = 0;
  if (0 < iVar6) {
    iStack_210 = 0;
    bVar3 = true;
    in_a2 = (ASN1_OBJECT *)0x0;
LAB_004c5f30:
    uVar15 = 0;
    bVar2 = false;
    pbVar18 = pbVar12;
LAB_004c5f3c:
    do {
      pbVar12 = pbVar18 + 1;
      iVar6 = iVar6 + -1;
      bVar1 = *pbVar18;
      uVar13 = (uint)bVar1;
      pbVar18 = pbVar12;
      if (iVar6 == 0) {
        if ((char)bVar1 < '\0') goto LAB_004c5fac;
        if (!bVar2) {
          uVar15 = uVar15 | uVar13;
LAB_004c616c:
          if (!bVar3) goto LAB_004c6174;
          bVar2 = false;
          if (0x4f < uVar15) goto LAB_004c6348;
          goto LAB_004c6220;
        }
LAB_004c6014:
        iVar8 = (*(code *)PTR_BN_add_word_006a81bc)(in_a2,uVar13 & 0x7f);
        if (iVar8 == 0) goto LAB_004c5fac;
        if (-1 < (char)bVar1) goto code_r0x004c6034;
      }
      else {
        if (bVar2) goto LAB_004c6014;
        uVar15 = uVar15 | uVar13 & 0x7f;
        if (-1 < (char)bVar1) goto LAB_004c616c;
        if (uVar15 < 0x2000000) {
          uVar15 = uVar15 << 7;
          goto LAB_004c5f3c;
        }
        if ((in_a2 == (ASN1_OBJECT *)0x0) &&
           (in_a2 = (ASN1_OBJECT *)(*(code *)PTR_BN_new_006a82b4)(), in_a2 == (ASN1_OBJECT *)0x0)) {
          iStack_210 = -1;
          break;
        }
        iVar8 = (*(code *)PTR_BN_set_word_006a8820)(in_a2,uVar15);
        if (iVar8 == 0) goto LAB_004c5fb4;
        bVar2 = true;
      }
      iVar8 = (*(code *)PTR_BN_lshift_006a95b8)(in_a2,in_a2,7);
      if (iVar8 == 0) goto LAB_004c5fac;
    } while( true );
  }
  goto LAB_004c5fc8;
code_r0x004c6034:
  if (bVar3) {
    if (uVar15 < 0x50) {
LAB_004c6220:
      uVar13 = uVar15 / 0x28;
      uVar15 = uVar15 - (uVar13 * 8 + ((uint)((ulonglong)uVar15 * 0xcccccccd >> 0x20) & 0xffffffe0))
      ;
    }
    else if (bVar2) {
      iVar8 = (*(code *)PTR_BN_sub_word_006a95bc)(in_a2,0x50);
      if (iVar8 == 0) goto LAB_004c5fac;
      uVar13 = 2;
    }
    else {
LAB_004c6348:
      uVar15 = uVar15 - 0x50;
      uVar13 = 2;
    }
    if ((pcStack_214 != (char *)0x0) && (0 < (int)pcStack_194)) {
      pcStack_194 = (char *)((int)pcStack_194 + -1);
      *pcStack_214 = (char)uVar13 + '0';
      pcStack_214 = pcStack_214 + 1;
    }
    iStack_210 = iStack_210 + 1;
    if (!bVar2) {
LAB_004c6174:
      (*(code *)PTR_BIO_snprintf_006a8060)(auStack_1e0,0x1a,&DAT_0064d8b0,uVar15);
      iVar8 = (*(code *)PTR_strlen_006aab30)(auStack_1e0);
      if ((pcStack_214 != (char *)0x0) && (0 < (int)pcStack_194)) {
        (*(code *)PTR_BUF_strlcpy_006a8064)(pcStack_214,auStack_1e0,pcStack_194);
        ppAVar4 = (ASN1_OBJECT **)pcStack_194;
        if ((int)pcStack_194 < iVar8) {
          pcStack_194 = (char *)0x0;
          pcStack_214 = pcStack_214 + (int)ppAVar4;
        }
        else {
          pcStack_214 = pcStack_214 + iVar8;
          pcStack_194 = (char *)((int)pcStack_194 - iVar8);
        }
      }
      iStack_210 = iStack_210 + iVar8;
      goto LAB_004c61f4;
    }
  }
  pvVar5 = (void *)(*(code *)PTR_BN_bn2dec_006a8f28)(in_a2);
  if (pvVar5 == (void *)0x0) {
LAB_004c5fac:
    iStack_210 = -1;
    if (in_a2 != (ASN1_OBJECT *)0x0) {
LAB_004c5fb4:
      (*(code *)PTR_BN_free_006a811c)(in_a2);
      iStack_210 = -1;
    }
    goto LAB_004c5fc8;
  }
  iVar8 = (*(code *)PTR_strlen_006aab30)(pvVar5);
  if (pcStack_214 != (char *)0x0) {
    if (0 < (int)pcStack_194) {
      pcStack_194 = (char *)((int)pcStack_194 + -1);
      *pcStack_214 = '.';
      pcStack_214 = pcStack_214 + 1;
    }
    (*(code *)PTR_BUF_strlcpy_006a8064)(pcStack_214,pvVar5,pcStack_194);
    ppAVar4 = (ASN1_OBJECT **)pcStack_194;
    if (iVar8 <= (int)pcStack_194) {
      pcStack_214 = pcStack_214 + iVar8;
      pcStack_194 = (char *)((int)pcStack_194 - iVar8);
      iStack_210 = iVar8 + iStack_210 + 1;
      CRYPTO_free(pvVar5);
      goto LAB_004c61f4;
    }
    pcStack_194 = (char *)0x0;
    pcStack_214 = pcStack_214 + (int)ppAVar4;
  }
  iStack_210 = iVar8 + iStack_210 + 1;
  CRYPTO_free(pvVar5);
LAB_004c61f4:
  bVar3 = false;
  if (iVar6 < 1) goto code_r0x004c61fc;
  goto LAB_004c5f30;
code_r0x004c61fc:
  if (in_a2 != (ASN1_OBJECT *)0x0) {
    (*(code *)PTR_BN_free_006a811c)(in_a2);
  }
LAB_004c5fc8:
  if (iStack_1c4 == *(int *)puVar17) {
    return iStack_210;
  }
  pcVar16 = (code *)PTR___stack_chk_fail_006aabb8;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_004c6454:
  (*pcVar16)(8,0x66,0x65,"obj_dat.c",0x16a);
  (*(code *)PTR_ERR_put_error_006a9030)(8,0x68,0x65,"obj_dat.c",0x14a);
  pbVar12 = in_a2->data;
  goto LAB_004c5efc;
}

