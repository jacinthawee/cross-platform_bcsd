
char * OBJ_nid2ln(int n)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  char *pcVar4;
  int iVar5;
  void *ptr;
  int *piVar6;
  int iVar7;
  undefined4 *in_a1;
  undefined4 *puVar8;
  ASN1_OBJECT *in_a2;
  char *in_a3;
  byte *pbVar9;
  char *pcVar10;
  int unaff_s1;
  int unaff_s2;
  int unaff_s4;
  uint uVar11;
  ASN1_OBJECT *unaff_s5;
  uint uVar12;
  undefined1 *unaff_s6;
  undefined1 *unaff_s7;
  code *pcVar13;
  undefined *puVar14;
  char *unaff_s8;
  byte *pbVar15;
  char *pcStack_124;
  char *pcStack_120;
  undefined4 uStack_110;
  undefined *puStack_10c;
  undefined auStack_108 [8];
  uint uStack_100;
  undefined auStack_f0 [28];
  int iStack_d4;
  char *pcStack_d0;
  int iStack_cc;
  int iStack_c8;
  undefined *puStack_c4;
  int iStack_c0;
  ASN1_OBJECT *pAStack_bc;
  undefined1 *puStack_b8;
  undefined1 *puStack_b4;
  char *pcStack_b0;
  code *pcStack_ac;
  undefined4 *puStack_a4;
  undefined *puStack_98;
  char *pcStack_8c;
  undefined4 uStack_84;
  int iStack_80;
  char *pcStack_7c;
  undefined *puStack_78;
  undefined4 local_2c;
  undefined *local_28;
  undefined auStack_24 [8];
  int local_1c;
  int local_c;
  
  pcStack_d0 = PTR___stack_chk_guard_006a9ae8;
  local_c = *(int *)PTR___stack_chk_guard_006a9ae8;
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
LAB_004c2ae0:
        in_a3 = "obj_dat.c";
        in_a2 = (ASN1_OBJECT *)&DAT_00000065;
        in_a1 = (undefined4 *)0x66;
        (*(code *)PTR_ERR_put_error_006a7f34)(8);
        pcVar4 = (char *)0x0;
        goto LAB_004c2aa0;
      }
    }
    pcVar4 = *(char **)(nid_objs + (n - iVar7) + 4);
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
    if (iVar7 == 0) goto LAB_004c2ae0;
    pcVar4 = *(char **)(*(int *)(iVar7 + 4) + 4);
  }
LAB_004c2aa0:
  if (local_c == *(int *)pcStack_d0) {
    return pcVar4;
  }
  iVar7 = local_c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_c4 = PTR___stack_chk_guard_006a9ae8;
  puStack_78 = pcStack_d0;
  puStack_98 = &_gp;
  pcStack_7c = *(char **)PTR___stack_chk_guard_006a9ae8;
  pcVar4 = (char *)0x0;
  iStack_c8 = unaff_s2;
  puVar14 = &_gp;
  if ((iVar7 != 0) && (pcVar4 = *(char **)(iVar7 + 8), iStack_c8 = iVar7, pcVar4 == (char *)0x0)) {
    unaff_s5 = *(ASN1_OBJECT **)(iVar7 + 0xc);
    pcVar4 = (char *)0x0;
    if (unaff_s5 != (ASN1_OBJECT *)0x0) {
      if (added == 0) {
LAB_004c2bfc:
        unaff_s8 = (char *)0x0;
        unaff_s7 = obj_objs;
        unaff_s6 = nid_objs;
        pcStack_d0 = (char *)0x359;
        pcVar4 = (char *)0x359;
        puVar14 = puStack_98;
        do {
          pcVar10 = (char *)((int)pcStack_d0 >> 1);
          iVar5 = *(int *)(obj_objs + (int)pcVar10 * 4);
          unaff_s4 = iVar5 * 8;
          unaff_s1 = iVar5 * 0x20;
          if (unaff_s5 == *(ASN1_OBJECT **)(nid_objs + iVar5 * 0x18 + 0xc)) {
            in_a1 = *(undefined4 **)(nid_objs + iVar5 * 0x18 + 0x10);
            in_a2 = unaff_s5;
            pcStack_8c = pcVar4;
            iVar5 = (**(code **)(puVar14 + -0x5310))(*(undefined4 *)(iVar7 + 0x10));
            puVar14 = puStack_98;
            if (-1 < iVar5) {
              puVar8 = in_a1;
              in_a3 = pcStack_8c;
              pcVar4 = pcStack_8c;
              pcStack_d0 = pcVar10;
              if (iVar5 == 0) goto LAB_004c2cf8;
LAB_004c2c6c:
              unaff_s8 = pcVar10 + 1;
              pcVar10 = pcVar4;
            }
          }
          else if (-1 < (int)unaff_s5 - (int)*(ASN1_OBJECT **)(nid_objs + iVar5 * 0x18 + 0xc))
          goto LAB_004c2c6c;
          pcStack_d0 = pcVar10 + (int)unaff_s8;
          pcVar4 = pcVar10;
        } while ((int)unaff_s8 < (int)pcVar10);
        pcVar4 = (char *)0x0;
        in_a3 = pcVar10;
      }
      else {
        in_a1 = &uStack_84;
        uStack_84 = 0;
        iStack_80 = iVar7;
        iVar5 = (*(code *)PTR_lh_retrieve_006a73b0)();
        puVar14 = puStack_98;
        if (iVar5 == 0) {
          unaff_s5 = *(ASN1_OBJECT **)(iVar7 + 0xc);
          if (unaff_s5 != (ASN1_OBJECT *)0x0) goto LAB_004c2bfc;
          iVar7 = 0;
          unaff_s7 = obj_objs;
          unaff_s6 = nid_objs;
          puVar8 = (undefined4 *)0x359;
          do {
            in_a1 = (undefined4 *)(iVar7 + (int)puVar8 >> 1);
            iVar5 = *(int *)(obj_objs + (int)in_a1 * 4);
            unaff_s4 = iVar5 * 8;
            unaff_s1 = iVar5 * 0x20;
            if (*(int *)(nid_objs + iVar5 * 0x18 + 0xc) == 0) goto LAB_004c2cf8;
            if (*(int *)(nid_objs + iVar5 * 0x18 + 0xc) < 1) {
              iVar7 = (int)in_a1 + 1;
              in_a1 = puVar8;
            }
            pcVar4 = (char *)0x0;
            puVar8 = in_a1;
          } while (iVar7 < (int)in_a1);
        }
        else {
          pcVar4 = *(char **)(*(int *)(iVar5 + 4) + 8);
        }
      }
    }
  }
  goto LAB_004c2bb4;
LAB_004c2cf8:
  in_a1 = puVar8;
  unaff_s7 = obj_objs;
  unaff_s6 = nid_objs;
  pcVar4 = *(char **)(nid_objs + (unaff_s1 - unaff_s4) + 8);
  puVar14 = puStack_98;
LAB_004c2bb4:
  if (pcStack_7c == *(char **)puStack_c4) {
    return pcVar4;
  }
  pcStack_ac = OBJ_obj2txt;
  pcStack_124 = pcStack_7c;
  (**(code **)(puVar14 + -0x5330))();
  puVar14 = PTR___stack_chk_guard_006a9ae8;
  iStack_d4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((pcStack_124 != (char *)0x0) && (0 < (int)in_a1)) {
    *pcStack_124 = '\0';
  }
  pcStack_120 = (char *)0x0;
  iStack_cc = unaff_s1;
  iStack_c0 = unaff_s4;
  pAStack_bc = unaff_s5;
  puStack_b8 = unaff_s6;
  puStack_b4 = unaff_s7;
  pcStack_b0 = unaff_s8;
  puStack_a4 = in_a1;
  if (in_a2 == (ASN1_OBJECT *)0x0) goto LAB_004c2e70;
  pbVar9 = in_a2->data;
  if (pbVar9 == (byte *)0x0) goto LAB_004c2e70;
  if (in_a3 != (char *)0x0) goto LAB_004c2da0;
  uVar12 = OBJ_obj2nid(in_a2);
  if (uVar12 == 0) {
LAB_004c3128:
    pbVar9 = in_a2->data;
  }
  else {
    if (uVar12 < 0x398) {
      iVar7 = uVar12 * 0x18;
      piVar6 = (int *)(nid_objs + iVar7);
      pcVar13 = (code *)PTR_ERR_put_error_006a7f34;
      if (*(int *)(nid_objs + iVar7 + 8) == 0) goto LAB_004c32f8;
      iVar7 = *(int *)(nid_objs + iVar7 + 4);
      if (iVar7 != 0) goto LAB_004c31bc;
    }
    else {
      if (added != 0) {
        uStack_110 = 3;
        puStack_10c = auStack_108;
        uStack_100 = uVar12;
        iVar7 = (*(code *)PTR_lh_retrieve_006a73b0)(added,&uStack_110);
        if (iVar7 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(8,0x66,0x65,"obj_dat.c",0x184);
        }
        else {
          iVar7 = *(int *)(*(int *)(iVar7 + 4) + 4);
          if (iVar7 != 0) goto LAB_004c31bc;
        }
      }
      if (added == 0) goto LAB_004c3128;
      uStack_110 = 3;
      puStack_10c = auStack_108;
      uStack_100 = uVar12;
      iVar7 = (*(code *)PTR_lh_retrieve_006a73b0)(added,&uStack_110);
      if (iVar7 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(8,0x68,0x65,"obj_dat.c",0x169);
        pbVar9 = in_a2->data;
        goto LAB_004c2da0;
      }
      piVar6 = *(int **)(iVar7 + 4);
    }
    iVar7 = *piVar6;
    if (iVar7 != 0) {
LAB_004c31bc:
      if (pcStack_124 != (char *)0x0) {
        (*(code *)PTR_BUF_strlcpy_006a6f64)(pcStack_124,iVar7,puStack_a4);
      }
      pcStack_120 = (char *)(*(code *)PTR_strlen_006a9a24)(iVar7);
      goto LAB_004c2e70;
    }
    pbVar9 = in_a2->data;
  }
LAB_004c2da0:
  iVar7 = in_a2->length;
  pcStack_120 = (char *)0x0;
  if (0 < iVar7) {
    pcStack_120 = (char *)0x0;
    bVar3 = true;
    in_a2 = (ASN1_OBJECT *)0x0;
LAB_004c2dd4:
    uVar12 = 0;
    bVar2 = false;
    pbVar15 = pbVar9;
LAB_004c2de0:
    do {
      pbVar9 = pbVar15 + 1;
      iVar7 = iVar7 + -1;
      bVar1 = *pbVar15;
      uVar11 = (uint)bVar1;
      pbVar15 = pbVar9;
      if (iVar7 == 0) {
        if ((char)bVar1 < '\0') goto LAB_004c2e50;
        if (!bVar2) {
          uVar12 = uVar12 | uVar11;
LAB_004c3020:
          if (!bVar3) goto LAB_004c3028;
          bVar2 = false;
          if (0x4f < uVar12) goto LAB_004c31ec;
          goto LAB_004c30d4;
        }
LAB_004c2eb8:
        iVar5 = (*(code *)PTR_BN_add_word_006a70bc)(in_a2,uVar11 & 0x7f);
        if (iVar5 == 0) goto LAB_004c2e50;
        if (-1 < (char)bVar1) goto code_r0x004c2ed8;
      }
      else {
        if (bVar2) goto LAB_004c2eb8;
        uVar12 = uVar12 | uVar11 & 0x7f;
        if (-1 < (char)bVar1) goto LAB_004c3020;
        if (uVar12 < 0x2000000) {
          uVar12 = uVar12 << 7;
          goto LAB_004c2de0;
        }
        if ((in_a2 == (ASN1_OBJECT *)0x0) &&
           (in_a2 = (ASN1_OBJECT *)(*(code *)PTR_BN_new_006a71b4)(), in_a2 == (ASN1_OBJECT *)0x0)) {
          pcStack_120 = (char *)0xffffffff;
          break;
        }
        iVar5 = (*(code *)PTR_BN_set_word_006a7730)(in_a2,uVar12);
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
    if (uVar12 < 0x50) {
LAB_004c30d4:
      uVar11 = uVar12 / 0x28;
      uVar12 = uVar12 - (uVar11 * 8 + ((uint)((ulonglong)uVar12 * 0xcccccccd >> 0x20) & 0xffffffe0))
      ;
    }
    else if (bVar2) {
      iVar5 = (*(code *)PTR_BN_sub_word_006a849c)(in_a2,0x50);
      if (iVar5 == 0) goto LAB_004c2e50;
      uVar11 = 2;
    }
    else {
LAB_004c31ec:
      uVar12 = uVar12 - 0x50;
      uVar11 = 2;
    }
    if ((pcStack_124 != (char *)0x0) && (1 < (int)puStack_a4)) {
      pcStack_124[1] = '\0';
      puStack_a4 = (undefined4 *)((int)puStack_a4 + -1);
      *pcStack_124 = (char)uVar11 + '0';
      pcStack_124 = pcStack_124 + 1;
    }
    pcStack_120 = pcStack_120 + 1;
    if (!bVar2) {
LAB_004c3028:
      (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_f0,0x1a,&DAT_0064cf14,uVar12);
      iVar5 = (*(code *)PTR_strlen_006a9a24)(auStack_f0);
      if ((pcStack_124 != (char *)0x0) && (0 < (int)puStack_a4)) {
        (*(code *)PTR_BUF_strlcpy_006a6f64)(pcStack_124,auStack_f0,puStack_a4);
        puVar8 = puStack_a4;
        if ((int)puStack_a4 < iVar5) {
          puStack_a4 = (undefined4 *)0x0;
          pcStack_124 = pcStack_124 + (int)puVar8;
        }
        else {
          pcStack_124 = pcStack_124 + iVar5;
          puStack_a4 = (undefined4 *)((int)puStack_a4 - iVar5);
        }
      }
      pcStack_120 = pcStack_120 + iVar5;
      goto LAB_004c30a8;
    }
  }
  ptr = (void *)(*(code *)PTR_BN_bn2dec_006a7e38)(in_a2);
  if (ptr == (void *)0x0) {
LAB_004c2e50:
    pcStack_120 = (char *)0xffffffff;
    if (in_a2 != (ASN1_OBJECT *)0x0) {
LAB_004c2e58:
      (*(code *)PTR_BN_free_006a701c)(in_a2);
      pcStack_120 = (char *)0xffffffff;
    }
    goto LAB_004c2e70;
  }
  iVar5 = (*(code *)PTR_strlen_006a9a24)(ptr);
  if (pcStack_124 != (char *)0x0) {
    if (1 < (int)puStack_a4) {
      pcStack_124[1] = '\0';
      puStack_a4 = (undefined4 *)((int)puStack_a4 + -1);
      *pcStack_124 = '.';
      pcStack_124 = pcStack_124 + 1;
    }
    (*(code *)PTR_BUF_strlcpy_006a6f64)(pcStack_124,ptr,puStack_a4);
    puVar8 = puStack_a4;
    if (iVar5 <= (int)puStack_a4) {
      pcStack_124 = pcStack_124 + iVar5;
      puStack_a4 = (undefined4 *)((int)puStack_a4 - iVar5);
      pcStack_120 = pcStack_120 + iVar5 + 1;
      CRYPTO_free(ptr);
      goto LAB_004c30a8;
    }
    puStack_a4 = (undefined4 *)0x0;
    pcStack_124 = pcStack_124 + (int)puVar8;
  }
  pcStack_120 = pcStack_120 + iVar5 + 1;
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
  if (iStack_d4 == *(int *)puVar14) {
    return pcStack_120;
  }
  pcVar13 = (code *)PTR___stack_chk_fail_006a9ab0;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004c32f8:
  (*pcVar13)(8,0x66,0x65,"obj_dat.c",0x176);
  (*(code *)PTR_ERR_put_error_006a7f34)(8,0x68,0x65,"obj_dat.c",0x15b);
  pbVar9 = in_a2->data;
  goto LAB_004c2da0;
}

