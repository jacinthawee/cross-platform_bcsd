
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
  int *piVar9;
  uchar *puVar10;
  ASN1_OBJECT *pAVar11;
  ASN1_OBJECT *in_a2;
  char *in_a3;
  char *pcVar12;
  byte *pbVar13;
  ASN1_OBJECT *unaff_s0;
  char *pcVar14;
  ASN1_OBJECT *unaff_s1;
  uint uVar15;
  ASN1_OBJECT *unaff_s5;
  uint uVar16;
  undefined1 *unaff_s6;
  undefined1 *unaff_s7;
  code *pcVar17;
  undefined *puVar18;
  char *unaff_s8;
  byte *pbVar19;
  char *pcStack_21c;
  int iStack_218;
  undefined4 uStack_208;
  undefined *puStack_204;
  undefined auStack_200 [8];
  uint uStack_1f8;
  undefined auStack_1e8 [28];
  int iStack_1cc;
  char *pcStack_1c8;
  ASN1_OBJECT *pAStack_1c4;
  ASN1_OBJECT *pAStack_1c0;
  undefined *puStack_1bc;
  undefined *puStack_1b8;
  ASN1_OBJECT *pAStack_1b4;
  undefined1 *puStack_1b0;
  undefined1 *puStack_1ac;
  char *pcStack_1a8;
  code *pcStack_1a4;
  char *pcStack_19c;
  undefined *puStack_190;
  char *pcStack_184;
  ASN1_OBJECT *pAStack_17c;
  ASN1_OBJECT *pAStack_178;
  char *pcStack_174;
  undefined *puStack_170;
  ASN1_OBJECT *pAStack_16c;
  ASN1_OBJECT *pAStack_168;
  undefined *puStack_164;
  undefined *puStack_160;
  ASN1_OBJECT *pAStack_15c;
  ASN1_OBJECT *pAStack_124;
  undefined *puStack_120;
  undefined auStack_11c [8];
  uint uStack_114;
  ASN1_OBJECT *pAStack_104;
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
  
  puStack_1b8 = PTR___stack_chk_guard_006a9ae8;
  local_40 = &_gp;
  local_34.sn = (char *)0x0;
  local_34.ln = (char **)0x0;
  local_34.nid = 0;
  local_34.length = 0;
  local_34.data = *(uchar **)PTR___stack_chk_guard_006a9ae8;
  pcStack_19c = "$\x04";
  if (added == 0) {
    pcVar17 = added_obj_LHASH_COMP;
    added = (*(code *)PTR_lh_new_006a740c)(added_obj_LHASH_HASH);
    pcStack_19c = (char *)pcVar17;
    puVar18 = local_40;
    if (added != 0) goto LAB_004c25b0;
LAB_004c2790:
    iVar6 = 0;
  }
  else {
LAB_004c25b0:
    unaff_s1 = OBJ_dup(obj);
    if (unaff_s1 == (ASN1_OBJECT *)0x0) {
LAB_004c2728:
      unaff_s0 = &local_34;
      obj = (ASN1_OBJECT *)&local_34.data;
      puVar18 = local_40;
      do {
        if (unaff_s0->sn != (char *)0x0) {
          CRYPTO_free(unaff_s0->sn);
          puVar18 = local_40;
        }
        unaff_s0 = (ASN1_OBJECT *)&unaff_s0->ln;
      } while (obj != unaff_s0);
      if (unaff_s1 == (ASN1_OBJECT *)0x0) goto LAB_004c2790;
      CRYPTO_free(unaff_s1);
      iVar6 = 0;
      puVar18 = local_40;
    }
    else {
      in_a2 = (ASN1_OBJECT *)0x10e;
      pcStack_19c = "obj_dat.c";
      local_34.length = (int)CRYPTO_malloc(8,"obj_dat.c",0x10e);
      if ((void *)local_34.length == (void *)0x0) {
LAB_004c2704:
        in_a3 = "obj_dat.c";
        in_a2 = (ASN1_OBJECT *)&DAT_00000041;
        pcStack_19c = &DAT_00000069;
        local_48 = 0x12f;
        (**(code **)(local_40 + -0x6eac))(8);
        goto LAB_004c2728;
      }
      if ((unaff_s1->length != 0) && (obj->data != (uchar *)0x0)) {
        in_a2 = (ASN1_OBJECT *)0x112;
        pcStack_19c = "obj_dat.c";
        local_34.sn = (char *)CRYPTO_malloc(8,"obj_dat.c",0x112);
        if (local_34.sn == (char *)0x0) goto LAB_004c2704;
      }
      if (unaff_s1->sn != (char *)0x0) {
        in_a2 = (ASN1_OBJECT *)0x117;
        pcStack_19c = "obj_dat.c";
        local_34.ln = (char **)CRYPTO_malloc(8,"obj_dat.c",0x117);
        if (local_34.ln == (char **)0x0) goto LAB_004c2704;
      }
      if (unaff_s1->ln != (char **)0x0) {
        in_a2 = (ASN1_OBJECT *)0x11c;
        pcStack_19c = "obj_dat.c";
        local_34.nid = (int)CRYPTO_malloc(8,"obj_dat.c",0x11c);
        if ((void *)local_34.nid == (void *)0x0) goto LAB_004c2704;
      }
      obj = &local_34;
      unaff_s0 = (ASN1_OBJECT *)0x0;
      unaff_s5 = (ASN1_OBJECT *)&SUB_00000004;
      puVar18 = local_40;
      do {
        iVar6 = added;
        ppAVar4 = (ASN1_OBJECT **)obj->sn;
        pcVar17 = *(code **)(puVar18 + -0x79cc);
        if (ppAVar4 != (ASN1_OBJECT **)0x0) {
          *ppAVar4 = unaff_s0;
          ppAVar4[1] = unaff_s1;
          pvVar5 = (void *)(*pcVar17)(iVar6);
          pcStack_19c = (char *)ppAVar4;
          puVar18 = local_40;
          if (pvVar5 != (void *)0x0) {
            CRYPTO_free(pvVar5);
            pcStack_19c = (char *)ppAVar4;
            puVar18 = local_40;
          }
        }
        unaff_s0 = (ASN1_OBJECT *)((int)&unaff_s0->sn + 1);
        obj = (ASN1_OBJECT *)&obj->ln;
      } while (unaff_s0 != (ASN1_OBJECT *)&SUB_00000004);
      iVar6 = unaff_s1->nid;
      unaff_s1->flags = unaff_s1->flags & 0xfffffff2;
    }
  }
  if (local_34.data == *(uchar **)puStack_1b8) {
    return iVar6;
  }
  pcStack_5c = OBJ_nid2obj;
  puVar10 = local_34.data;
  (**(code **)(puVar18 + -0x5330))();
  puStack_b0 = PTR___stack_chk_guard_006a9ae8;
  puStack_90 = &_gp;
  uStack_64 = *(uint *)PTR___stack_chk_guard_006a9ae8;
  pAStack_60 = unaff_s0;
  if (puVar10 < (uchar *)0x398) {
    if (puVar10 == (uchar *)0x0) {
      puVar7 = nid_objs;
    }
    else {
      pcStack_19c = *(char **)(nid_objs + (int)puVar10 * 0x18 + 8);
      if ((ASN1_OBJECT **)pcStack_19c == (ASN1_OBJECT **)0x0) {
        uStack_98 = 0x140;
        pcVar17 = (code *)PTR_ERR_put_error_006a7f34;
LAB_004c2890:
        in_a3 = "obj_dat.c";
        in_a2 = (ASN1_OBJECT *)&DAT_00000065;
        pcStack_19c = (char *)0x67;
        (*pcVar17)(8);
        puVar7 = (undefined1 *)0x0;
      }
      else {
        puVar7 = nid_objs + (int)puVar10 * 0x18;
      }
    }
  }
  else if (added == 0) {
    puVar7 = (undefined1 *)0x0;
  }
  else {
    pcStack_19c = (char *)&pAStack_84;
    pAStack_84 = (ASN1_OBJECT *)0x3;
    puStack_80 = auStack_7c;
    puStack_74 = puVar10;
    iVar6 = (*(code *)PTR_lh_retrieve_006a73b0)(added);
    if (iVar6 == 0) {
      pcVar17 = *(code **)(puStack_90 + -0x6eac);
      uStack_98 = 0x14e;
      goto LAB_004c2890;
    }
    puVar7 = *(undefined1 **)(iVar6 + 4);
  }
  if (uStack_64 == *(uint *)puStack_b0) {
    return (int)puVar7;
  }
  pcStack_ac = OBJ_nid2sn;
  uVar16 = uStack_64;
  (**(code **)(puStack_90 + -0x5330))();
  puStack_100 = PTR___stack_chk_guard_006a9ae8;
  puStack_e0 = &_gp;
  uStack_b4 = *(uint *)PTR___stack_chk_guard_006a9ae8;
  if (uVar16 < 0x398) {
    if (uVar16 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = uVar16 * 8;
      pcStack_19c = *(char **)(nid_objs + uVar16 * 0x18 + 8);
      in_a3 = "TBEX";
      uVar16 = uVar16 * 0x20;
      if ((ASN1_OBJECT **)pcStack_19c == (ASN1_OBJECT **)0x0) {
        uStack_e8 = 0x15b;
        pcVar17 = (code *)PTR_ERR_put_error_006a7f34;
LAB_004c29b8:
        in_a3 = "obj_dat.c";
        in_a2 = (ASN1_OBJECT *)&DAT_00000065;
        pcStack_19c = &DAT_00000068;
        (*pcVar17)(8);
        iVar6 = 0;
        goto LAB_004c2978;
      }
    }
    iVar6 = *(int *)(nid_objs + (uVar16 - iVar6));
  }
  else if (added == 0) {
    iVar6 = 0;
  }
  else {
    pcStack_19c = (char *)&pAStack_d4;
    pAStack_d4 = (ASN1_OBJECT *)0x3;
    puStack_d0 = auStack_cc;
    uStack_c4 = uVar16;
    iVar6 = (*(code *)PTR_lh_retrieve_006a73b0)(added);
    if (iVar6 == 0) {
      pcVar17 = *(code **)(puStack_e0 + -0x6eac);
      uStack_e8 = 0x169;
      goto LAB_004c29b8;
    }
    iVar6 = **(int **)(iVar6 + 4);
  }
LAB_004c2978:
  if (uStack_b4 == *(uint *)puStack_100) {
    return iVar6;
  }
  pcStack_fc = OBJ_nid2ln;
  uVar16 = uStack_b4;
  (**(code **)(puStack_e0 + -0x5330))();
  pcStack_1c8 = PTR___stack_chk_guard_006a9ae8;
  pAStack_104 = *(ASN1_OBJECT **)PTR___stack_chk_guard_006a9ae8;
  if (uVar16 < 0x398) {
    if (uVar16 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = uVar16 * 8;
      pcStack_19c = *(char **)(nid_objs + uVar16 * 0x18 + 8);
      in_a3 = "TBEX";
      uVar16 = uVar16 * 0x20;
      if ((ASN1_OBJECT **)pcStack_19c == (ASN1_OBJECT **)0x0) {
LAB_004c2ae0:
        in_a3 = "obj_dat.c";
        in_a2 = (ASN1_OBJECT *)&DAT_00000065;
        pcStack_19c = (char *)0x66;
        (*(code *)PTR_ERR_put_error_006a7f34)(8);
        iVar6 = 0;
        goto LAB_004c2aa0;
      }
    }
    iVar6 = *(int *)(nid_objs + (uVar16 - iVar6) + 4);
  }
  else if (added == 0) {
    iVar6 = 0;
  }
  else {
    pcStack_19c = (char *)&pAStack_124;
    pAStack_124 = (ASN1_OBJECT *)0x3;
    puStack_120 = auStack_11c;
    uStack_114 = uVar16;
    iVar6 = (*(code *)PTR_lh_retrieve_006a73b0)(added);
    if (iVar6 == 0) goto LAB_004c2ae0;
    iVar6 = *(int *)(*(int *)(iVar6 + 4) + 4);
  }
LAB_004c2aa0:
  if (pAStack_104 == *(ASN1_OBJECT **)pcStack_1c8) {
    return iVar6;
  }
  pAVar11 = pAStack_104;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_1bc = PTR___stack_chk_guard_006a9ae8;
  puStack_164 = &_gp_1;
  puStack_160 = puStack_1b8;
  puStack_170 = pcStack_1c8;
  puStack_190 = &_gp;
  pcStack_174 = *(char **)PTR___stack_chk_guard_006a9ae8;
  iVar6 = 0;
  pAStack_1c0 = obj;
  pAStack_1b4 = unaff_s5;
  puVar18 = &_gp;
  pAStack_16c = unaff_s1;
  pAStack_168 = obj;
  pAStack_15c = unaff_s5;
  if ((pAVar11 != (ASN1_OBJECT *)0x0) && (iVar6 = pAVar11->nid, pAStack_1c0 = pAVar11, iVar6 == 0))
  {
    pAStack_1b4 = (ASN1_OBJECT *)pAVar11->length;
    iVar6 = 0;
    if (pAStack_1b4 != (ASN1_OBJECT *)0x0) {
      if (added == 0) {
LAB_004c2bfc:
        unaff_s8 = (char *)0x0;
        unaff_s7 = obj_objs;
        unaff_s6 = nid_objs;
        pcStack_1c8 = (char *)0x359;
        pcVar12 = (char *)0x359;
        puVar18 = puStack_190;
        do {
          pcVar14 = (char *)((int)pcStack_1c8 >> 1);
          iVar6 = *(int *)(obj_objs + (int)pcVar14 * 4);
          puStack_1b8 = (undefined *)(iVar6 * 8);
          unaff_s1 = (ASN1_OBJECT *)(iVar6 * 0x20);
          if (pAStack_1b4 == *(ASN1_OBJECT **)(nid_objs + iVar6 * 0x18 + 0xc)) {
            pcStack_19c = *(char **)(nid_objs + iVar6 * 0x18 + 0x10);
            in_a2 = pAStack_1b4;
            pcStack_184 = pcVar12;
            iVar6 = (**(code **)(puVar18 + -0x5310))(pAVar11->data);
            puVar18 = puStack_190;
            if (-1 < iVar6) {
              ppAVar4 = (ASN1_OBJECT **)pcStack_19c;
              in_a3 = pcStack_184;
              pcVar12 = pcStack_184;
              pcStack_1c8 = pcVar14;
              if (iVar6 == 0) goto LAB_004c2cf8;
LAB_004c2c6c:
              unaff_s8 = pcVar14 + 1;
              pcVar14 = pcVar12;
            }
          }
          else if (-1 < (int)pAStack_1b4 - (int)*(ASN1_OBJECT **)(nid_objs + iVar6 * 0x18 + 0xc))
          goto LAB_004c2c6c;
          pcStack_1c8 = pcVar14 + (int)unaff_s8;
          pcVar12 = pcVar14;
        } while ((int)unaff_s8 < (int)pcVar14);
        iVar6 = 0;
        in_a3 = pcVar14;
      }
      else {
        pcStack_19c = (char *)&pAStack_17c;
        pAStack_17c = (ASN1_OBJECT *)0x0;
        pAStack_178 = pAVar11;
        iVar6 = (*(code *)PTR_lh_retrieve_006a73b0)();
        puVar18 = puStack_190;
        if (iVar6 == 0) {
          pAStack_1b4 = (ASN1_OBJECT *)pAVar11->length;
          if (pAStack_1b4 != (ASN1_OBJECT *)0x0) goto LAB_004c2bfc;
          iVar8 = 0;
          unaff_s7 = obj_objs;
          unaff_s6 = nid_objs;
          ppAVar4 = (ASN1_OBJECT **)0x359;
          do {
            pcStack_19c = (char *)(iVar8 + (int)ppAVar4 >> 1);
            iVar6 = *(int *)(obj_objs + (int)pcStack_19c * 4);
            puStack_1b8 = (undefined *)(iVar6 * 8);
            unaff_s1 = (ASN1_OBJECT *)(iVar6 * 0x20);
            if (*(int *)(nid_objs + iVar6 * 0x18 + 0xc) == 0) goto LAB_004c2cf8;
            if (*(int *)(nid_objs + iVar6 * 0x18 + 0xc) < 1) {
              iVar8 = (int)pcStack_19c + 1;
              pcStack_19c = (char *)ppAVar4;
            }
            iVar6 = 0;
            ppAVar4 = (ASN1_OBJECT **)pcStack_19c;
          } while (iVar8 < (int)pcStack_19c);
        }
        else {
          iVar6 = *(int *)(*(int *)(iVar6 + 4) + 8);
        }
      }
    }
  }
  goto LAB_004c2bb4;
LAB_004c2cf8:
  pcStack_19c = (char *)ppAVar4;
  unaff_s7 = obj_objs;
  unaff_s6 = nid_objs;
  iVar6 = *(int *)(nid_objs + (8 - (int)puStack_1b8) + (int)&unaff_s1->sn);
  puVar18 = puStack_190;
LAB_004c2bb4:
  if (pcStack_174 == *(char **)puStack_1bc) {
    return iVar6;
  }
  pcStack_1a4 = OBJ_obj2txt;
  pcStack_21c = pcStack_174;
  (**(code **)(puVar18 + -0x5330))();
  puVar18 = PTR___stack_chk_guard_006a9ae8;
  iStack_1cc = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((pcStack_21c != (char *)0x0) && (0 < (int)pcStack_19c)) {
    *pcStack_21c = '\0';
  }
  iStack_218 = 0;
  pAStack_1c4 = unaff_s1;
  puStack_1b0 = unaff_s6;
  puStack_1ac = unaff_s7;
  pcStack_1a8 = unaff_s8;
  if (in_a2 == (ASN1_OBJECT *)0x0) goto LAB_004c2e70;
  pbVar13 = in_a2->data;
  if (pbVar13 == (byte *)0x0) goto LAB_004c2e70;
  if (in_a3 != (char *)0x0) goto LAB_004c2da0;
  uVar16 = OBJ_obj2nid(in_a2);
  if (uVar16 == 0) {
LAB_004c3128:
    pbVar13 = in_a2->data;
  }
  else {
    if (uVar16 < 0x398) {
      iVar6 = uVar16 * 0x18;
      piVar9 = (int *)(nid_objs + iVar6);
      pcVar17 = (code *)PTR_ERR_put_error_006a7f34;
      if (*(int *)(nid_objs + iVar6 + 8) == 0) goto LAB_004c32f8;
      iVar6 = *(int *)(nid_objs + iVar6 + 4);
      if (iVar6 != 0) goto LAB_004c31bc;
    }
    else {
      if (added != 0) {
        uStack_208 = 3;
        puStack_204 = auStack_200;
        uStack_1f8 = uVar16;
        iVar6 = (*(code *)PTR_lh_retrieve_006a73b0)(added,&uStack_208);
        if (iVar6 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(8,0x66,0x65,"obj_dat.c",0x184);
        }
        else {
          iVar6 = *(int *)(*(int *)(iVar6 + 4) + 4);
          if (iVar6 != 0) goto LAB_004c31bc;
        }
      }
      if (added == 0) goto LAB_004c3128;
      uStack_208 = 3;
      puStack_204 = auStack_200;
      uStack_1f8 = uVar16;
      iVar6 = (*(code *)PTR_lh_retrieve_006a73b0)(added,&uStack_208);
      if (iVar6 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(8,0x68,0x65,"obj_dat.c",0x169);
        pbVar13 = in_a2->data;
        goto LAB_004c2da0;
      }
      piVar9 = *(int **)(iVar6 + 4);
    }
    iVar6 = *piVar9;
    if (iVar6 != 0) {
LAB_004c31bc:
      if (pcStack_21c != (char *)0x0) {
        (*(code *)PTR_BUF_strlcpy_006a6f64)(pcStack_21c,iVar6,pcStack_19c);
      }
      iStack_218 = (*(code *)PTR_strlen_006a9a24)(iVar6);
      goto LAB_004c2e70;
    }
    pbVar13 = in_a2->data;
  }
LAB_004c2da0:
  iVar6 = in_a2->length;
  iStack_218 = 0;
  if (0 < iVar6) {
    iStack_218 = 0;
    bVar3 = true;
    in_a2 = (ASN1_OBJECT *)0x0;
LAB_004c2dd4:
    uVar16 = 0;
    bVar2 = false;
    pbVar19 = pbVar13;
LAB_004c2de0:
    do {
      pbVar13 = pbVar19 + 1;
      iVar6 = iVar6 + -1;
      bVar1 = *pbVar19;
      uVar15 = (uint)bVar1;
      pbVar19 = pbVar13;
      if (iVar6 == 0) {
        if ((char)bVar1 < '\0') goto LAB_004c2e50;
        if (!bVar2) {
          uVar16 = uVar16 | uVar15;
LAB_004c3020:
          if (!bVar3) goto LAB_004c3028;
          bVar2 = false;
          if (0x4f < uVar16) goto LAB_004c31ec;
          goto LAB_004c30d4;
        }
LAB_004c2eb8:
        iVar8 = (*(code *)PTR_BN_add_word_006a70bc)(in_a2,uVar15 & 0x7f);
        if (iVar8 == 0) goto LAB_004c2e50;
        if (-1 < (char)bVar1) goto code_r0x004c2ed8;
      }
      else {
        if (bVar2) goto LAB_004c2eb8;
        uVar16 = uVar16 | uVar15 & 0x7f;
        if (-1 < (char)bVar1) goto LAB_004c3020;
        if (uVar16 < 0x2000000) {
          uVar16 = uVar16 << 7;
          goto LAB_004c2de0;
        }
        if ((in_a2 == (ASN1_OBJECT *)0x0) &&
           (in_a2 = (ASN1_OBJECT *)(*(code *)PTR_BN_new_006a71b4)(), in_a2 == (ASN1_OBJECT *)0x0)) {
          iStack_218 = -1;
          break;
        }
        iVar8 = (*(code *)PTR_BN_set_word_006a7730)(in_a2,uVar16);
        if (iVar8 == 0) goto LAB_004c2e58;
        bVar2 = true;
      }
      iVar8 = (*(code *)PTR_BN_lshift_006a8498)(in_a2,in_a2,7);
      if (iVar8 == 0) goto LAB_004c2e50;
    } while( true );
  }
  goto LAB_004c2e70;
code_r0x004c2ed8:
  if (bVar3) {
    if (uVar16 < 0x50) {
LAB_004c30d4:
      uVar15 = uVar16 / 0x28;
      uVar16 = uVar16 - (uVar15 * 8 + ((uint)((ulonglong)uVar16 * 0xcccccccd >> 0x20) & 0xffffffe0))
      ;
    }
    else if (bVar2) {
      iVar8 = (*(code *)PTR_BN_sub_word_006a849c)(in_a2,0x50);
      if (iVar8 == 0) goto LAB_004c2e50;
      uVar15 = 2;
    }
    else {
LAB_004c31ec:
      uVar16 = uVar16 - 0x50;
      uVar15 = 2;
    }
    if ((pcStack_21c != (char *)0x0) && (1 < (int)pcStack_19c)) {
      pcStack_21c[1] = '\0';
      pcStack_19c = (char *)((int)pcStack_19c + -1);
      *pcStack_21c = (char)uVar15 + '0';
      pcStack_21c = pcStack_21c + 1;
    }
    iStack_218 = iStack_218 + 1;
    if (!bVar2) {
LAB_004c3028:
      (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_1e8,0x1a,&DAT_0064cf14,uVar16);
      iVar8 = (*(code *)PTR_strlen_006a9a24)(auStack_1e8);
      if ((pcStack_21c != (char *)0x0) && (0 < (int)pcStack_19c)) {
        (*(code *)PTR_BUF_strlcpy_006a6f64)(pcStack_21c,auStack_1e8,pcStack_19c);
        ppAVar4 = (ASN1_OBJECT **)pcStack_19c;
        if ((int)pcStack_19c < iVar8) {
          pcStack_19c = (char *)0x0;
          pcStack_21c = pcStack_21c + (int)ppAVar4;
        }
        else {
          pcStack_21c = pcStack_21c + iVar8;
          pcStack_19c = (char *)((int)pcStack_19c - iVar8);
        }
      }
      iStack_218 = iStack_218 + iVar8;
      goto LAB_004c30a8;
    }
  }
  pvVar5 = (void *)(*(code *)PTR_BN_bn2dec_006a7e38)(in_a2);
  if (pvVar5 == (void *)0x0) {
LAB_004c2e50:
    iStack_218 = -1;
    if (in_a2 != (ASN1_OBJECT *)0x0) {
LAB_004c2e58:
      (*(code *)PTR_BN_free_006a701c)(in_a2);
      iStack_218 = -1;
    }
    goto LAB_004c2e70;
  }
  iVar8 = (*(code *)PTR_strlen_006a9a24)(pvVar5);
  if (pcStack_21c != (char *)0x0) {
    if (1 < (int)pcStack_19c) {
      pcStack_21c[1] = '\0';
      pcStack_19c = (char *)((int)pcStack_19c + -1);
      *pcStack_21c = '.';
      pcStack_21c = pcStack_21c + 1;
    }
    (*(code *)PTR_BUF_strlcpy_006a6f64)(pcStack_21c,pvVar5,pcStack_19c);
    ppAVar4 = (ASN1_OBJECT **)pcStack_19c;
    if (iVar8 <= (int)pcStack_19c) {
      pcStack_21c = pcStack_21c + iVar8;
      pcStack_19c = (char *)((int)pcStack_19c - iVar8);
      iStack_218 = iVar8 + iStack_218 + 1;
      CRYPTO_free(pvVar5);
      goto LAB_004c30a8;
    }
    pcStack_19c = (char *)0x0;
    pcStack_21c = pcStack_21c + (int)ppAVar4;
  }
  iStack_218 = iVar8 + iStack_218 + 1;
  CRYPTO_free(pvVar5);
LAB_004c30a8:
  bVar3 = false;
  if (iVar6 < 1) goto code_r0x004c30b0;
  goto LAB_004c2dd4;
code_r0x004c30b0:
  if (in_a2 != (ASN1_OBJECT *)0x0) {
    (*(code *)PTR_BN_free_006a701c)(in_a2);
  }
LAB_004c2e70:
  if (iStack_1cc == *(int *)puVar18) {
    return iStack_218;
  }
  pcVar17 = (code *)PTR___stack_chk_fail_006a9ab0;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004c32f8:
  (*pcVar17)(8,0x66,0x65,"obj_dat.c",0x176);
  (*(code *)PTR_ERR_put_error_006a7f34)(8,0x68,0x65,"obj_dat.c",0x15b);
  pbVar13 = in_a2->data;
  goto LAB_004c2da0;
}

