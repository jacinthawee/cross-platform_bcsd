
int OBJ_obj2nid(ASN1_OBJECT *o)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *ptr;
  int *piVar7;
  undefined4 *in_a1;
  undefined4 *puVar8;
  ASN1_OBJECT *in_a2;
  int in_a3;
  byte *pbVar9;
  int unaff_s0;
  int unaff_s1;
  ASN1_OBJECT *unaff_s2;
  int unaff_s4;
  uint uVar10;
  ASN1_OBJECT *unaff_s5;
  uint uVar11;
  undefined1 *unaff_s6;
  undefined1 *unaff_s7;
  code *pcVar12;
  undefined *puVar13;
  int unaff_s8;
  byte *pbVar14;
  char *pcStack_d4;
  int iStack_d0;
  undefined4 uStack_c0;
  undefined *puStack_bc;
  undefined auStack_b8 [8];
  uint uStack_b0;
  undefined auStack_a0 [28];
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  ASN1_OBJECT *pAStack_78;
  undefined *puStack_74;
  int iStack_70;
  ASN1_OBJECT *pAStack_6c;
  undefined1 *puStack_68;
  undefined1 *puStack_64;
  int iStack_60;
  code *pcStack_5c;
  undefined4 *puStack_54;
  undefined *local_48;
  int local_3c;
  undefined4 local_34;
  ASN1_OBJECT *local_30;
  char *local_2c;
  
  puStack_74 = PTR___stack_chk_guard_006a9ae8;
  local_48 = &_gp;
  local_2c = *(char **)PTR___stack_chk_guard_006a9ae8;
  iVar4 = 0;
  pAStack_78 = unaff_s2;
  puVar13 = &_gp;
  if ((o != (ASN1_OBJECT *)0x0) && (iVar4 = o->nid, pAStack_78 = o, iVar4 == 0)) {
    unaff_s5 = (ASN1_OBJECT *)o->length;
    iVar4 = 0;
    if (unaff_s5 != (ASN1_OBJECT *)0x0) {
      if (added == 0) {
LAB_004c2bfc:
        unaff_s8 = 0;
        unaff_s7 = obj_objs;
        unaff_s6 = nid_objs;
        unaff_s0 = 0x359;
        iVar4 = 0x359;
        puVar13 = local_48;
        do {
          iVar6 = unaff_s0 >> 1;
          iVar5 = *(int *)(obj_objs + iVar6 * 4);
          unaff_s4 = iVar5 * 8;
          unaff_s1 = iVar5 * 0x20;
          if (unaff_s5 == *(ASN1_OBJECT **)(nid_objs + iVar5 * 0x18 + 0xc)) {
            in_a1 = *(undefined4 **)(nid_objs + iVar5 * 0x18 + 0x10);
            in_a2 = unaff_s5;
            local_3c = iVar4;
            iVar5 = (**(code **)(puVar13 + -0x5310))(o->data);
            puVar13 = local_48;
            if (-1 < iVar5) {
              puVar8 = in_a1;
              in_a3 = local_3c;
              iVar4 = local_3c;
              unaff_s0 = iVar6;
              if (iVar5 == 0) goto LAB_004c2cf8;
LAB_004c2c6c:
              unaff_s8 = iVar6 + 1;
              iVar6 = iVar4;
            }
          }
          else if (-1 < (int)unaff_s5 - (int)*(ASN1_OBJECT **)(nid_objs + iVar5 * 0x18 + 0xc))
          goto LAB_004c2c6c;
          unaff_s0 = iVar6 + unaff_s8;
          iVar4 = iVar6;
        } while (unaff_s8 < iVar6);
        iVar4 = 0;
        in_a3 = iVar6;
      }
      else {
        in_a1 = &local_34;
        local_34 = 0;
        local_30 = o;
        iVar4 = (*(code *)PTR_lh_retrieve_006a73b0)();
        puVar13 = local_48;
        if (iVar4 == 0) {
          unaff_s5 = (ASN1_OBJECT *)o->length;
          if (unaff_s5 != (ASN1_OBJECT *)0x0) goto LAB_004c2bfc;
          iVar6 = 0;
          unaff_s7 = obj_objs;
          unaff_s6 = nid_objs;
          puVar8 = (undefined4 *)0x359;
          do {
            in_a1 = (undefined4 *)(iVar6 + (int)puVar8 >> 1);
            iVar4 = *(int *)(obj_objs + (int)in_a1 * 4);
            unaff_s4 = iVar4 * 8;
            unaff_s1 = iVar4 * 0x20;
            if (*(int *)(nid_objs + iVar4 * 0x18 + 0xc) == 0) goto LAB_004c2cf8;
            if (*(int *)(nid_objs + iVar4 * 0x18 + 0xc) < 1) {
              iVar6 = (int)in_a1 + 1;
              in_a1 = puVar8;
            }
            iVar4 = 0;
            puVar8 = in_a1;
          } while (iVar6 < (int)in_a1);
        }
        else {
          iVar4 = *(int *)(*(int *)(iVar4 + 4) + 8);
        }
      }
    }
  }
LAB_004c2bb4:
  if (local_2c == *(char **)puStack_74) {
    return iVar4;
  }
  pcStack_5c = OBJ_obj2txt;
  pcStack_d4 = local_2c;
  (**(code **)(puVar13 + -0x5330))();
  puVar13 = PTR___stack_chk_guard_006a9ae8;
  iStack_84 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((pcStack_d4 != (char *)0x0) && (0 < (int)in_a1)) {
    *pcStack_d4 = '\0';
  }
  iStack_d0 = 0;
  iStack_80 = unaff_s0;
  iStack_7c = unaff_s1;
  iStack_70 = unaff_s4;
  pAStack_6c = unaff_s5;
  puStack_68 = unaff_s6;
  puStack_64 = unaff_s7;
  iStack_60 = unaff_s8;
  puStack_54 = in_a1;
  if (in_a2 == (ASN1_OBJECT *)0x0) goto LAB_004c2e70;
  pbVar9 = in_a2->data;
  if (pbVar9 == (byte *)0x0) goto LAB_004c2e70;
  if (in_a3 != 0) goto LAB_004c2da0;
  uVar11 = OBJ_obj2nid(in_a2);
  if (uVar11 == 0) {
LAB_004c3128:
    pbVar9 = in_a2->data;
  }
  else {
    if (uVar11 < 0x398) {
      iVar4 = uVar11 * 0x18;
      piVar7 = (int *)(nid_objs + iVar4);
      pcVar12 = (code *)PTR_ERR_put_error_006a7f34;
      if (*(int *)(nid_objs + iVar4 + 8) == 0) goto LAB_004c32f8;
      iVar4 = *(int *)(nid_objs + iVar4 + 4);
      if (iVar4 != 0) goto LAB_004c31bc;
    }
    else {
      if (added != 0) {
        uStack_c0 = 3;
        puStack_bc = auStack_b8;
        uStack_b0 = uVar11;
        iVar4 = (*(code *)PTR_lh_retrieve_006a73b0)(added,&uStack_c0);
        if (iVar4 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(8,0x66,0x65,"obj_dat.c",0x184);
        }
        else {
          iVar4 = *(int *)(*(int *)(iVar4 + 4) + 4);
          if (iVar4 != 0) goto LAB_004c31bc;
        }
      }
      if (added == 0) goto LAB_004c3128;
      uStack_c0 = 3;
      puStack_bc = auStack_b8;
      uStack_b0 = uVar11;
      iVar4 = (*(code *)PTR_lh_retrieve_006a73b0)(added,&uStack_c0);
      if (iVar4 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(8,0x68,0x65,"obj_dat.c",0x169);
        pbVar9 = in_a2->data;
        goto LAB_004c2da0;
      }
      piVar7 = *(int **)(iVar4 + 4);
    }
    iVar4 = *piVar7;
    if (iVar4 != 0) {
LAB_004c31bc:
      if (pcStack_d4 != (char *)0x0) {
        (*(code *)PTR_BUF_strlcpy_006a6f64)(pcStack_d4,iVar4,puStack_54);
      }
      iStack_d0 = (*(code *)PTR_strlen_006a9a24)(iVar4);
      goto LAB_004c2e70;
    }
    pbVar9 = in_a2->data;
  }
LAB_004c2da0:
  iVar4 = in_a2->length;
  iStack_d0 = 0;
  if (0 < iVar4) {
    iStack_d0 = 0;
    bVar3 = true;
    in_a2 = (ASN1_OBJECT *)0x0;
LAB_004c2dd4:
    uVar11 = 0;
    bVar2 = false;
    pbVar14 = pbVar9;
LAB_004c2de0:
    do {
      pbVar9 = pbVar14 + 1;
      iVar4 = iVar4 + -1;
      bVar1 = *pbVar14;
      uVar10 = (uint)bVar1;
      pbVar14 = pbVar9;
      if (iVar4 == 0) {
        if ((char)bVar1 < '\0') goto LAB_004c2e50;
        if (!bVar2) {
          uVar11 = uVar11 | uVar10;
LAB_004c3020:
          if (!bVar3) goto LAB_004c3028;
          bVar2 = false;
          if (0x4f < uVar11) goto LAB_004c31ec;
          goto LAB_004c30d4;
        }
LAB_004c2eb8:
        iVar6 = (*(code *)PTR_BN_add_word_006a70bc)(in_a2,uVar10 & 0x7f);
        if (iVar6 == 0) goto LAB_004c2e50;
        if (-1 < (char)bVar1) goto code_r0x004c2ed8;
      }
      else {
        if (bVar2) goto LAB_004c2eb8;
        uVar11 = uVar11 | uVar10 & 0x7f;
        if (-1 < (char)bVar1) goto LAB_004c3020;
        if (uVar11 < 0x2000000) {
          uVar11 = uVar11 << 7;
          goto LAB_004c2de0;
        }
        if ((in_a2 == (ASN1_OBJECT *)0x0) &&
           (in_a2 = (ASN1_OBJECT *)(*(code *)PTR_BN_new_006a71b4)(), in_a2 == (ASN1_OBJECT *)0x0)) {
          iStack_d0 = -1;
          break;
        }
        iVar6 = (*(code *)PTR_BN_set_word_006a7730)(in_a2,uVar11);
        if (iVar6 == 0) goto LAB_004c2e58;
        bVar2 = true;
      }
      iVar6 = (*(code *)PTR_BN_lshift_006a8498)(in_a2,in_a2,7);
      if (iVar6 == 0) goto LAB_004c2e50;
    } while( true );
  }
  goto LAB_004c2e70;
LAB_004c2cf8:
  in_a1 = puVar8;
  unaff_s7 = obj_objs;
  unaff_s6 = nid_objs;
  iVar4 = *(int *)(nid_objs + (unaff_s1 - unaff_s4) + 8);
  puVar13 = local_48;
  goto LAB_004c2bb4;
code_r0x004c2ed8:
  if (bVar3) {
    if (uVar11 < 0x50) {
LAB_004c30d4:
      uVar10 = uVar11 / 0x28;
      uVar11 = uVar11 - (uVar10 * 8 + ((uint)((ulonglong)uVar11 * 0xcccccccd >> 0x20) & 0xffffffe0))
      ;
    }
    else if (bVar2) {
      iVar6 = (*(code *)PTR_BN_sub_word_006a849c)(in_a2,0x50);
      if (iVar6 == 0) goto LAB_004c2e50;
      uVar10 = 2;
    }
    else {
LAB_004c31ec:
      uVar11 = uVar11 - 0x50;
      uVar10 = 2;
    }
    if ((pcStack_d4 != (char *)0x0) && (1 < (int)puStack_54)) {
      pcStack_d4[1] = '\0';
      puStack_54 = (undefined4 *)((int)puStack_54 + -1);
      *pcStack_d4 = (char)uVar10 + '0';
      pcStack_d4 = pcStack_d4 + 1;
    }
    iStack_d0 = iStack_d0 + 1;
    if (!bVar2) {
LAB_004c3028:
      (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_a0,0x1a,&DAT_0064cf14,uVar11);
      iVar6 = (*(code *)PTR_strlen_006a9a24)(auStack_a0);
      if ((pcStack_d4 != (char *)0x0) && (0 < (int)puStack_54)) {
        (*(code *)PTR_BUF_strlcpy_006a6f64)(pcStack_d4,auStack_a0,puStack_54);
        puVar8 = puStack_54;
        if ((int)puStack_54 < iVar6) {
          puStack_54 = (undefined4 *)0x0;
          pcStack_d4 = pcStack_d4 + (int)puVar8;
        }
        else {
          pcStack_d4 = pcStack_d4 + iVar6;
          puStack_54 = (undefined4 *)((int)puStack_54 - iVar6);
        }
      }
      iStack_d0 = iStack_d0 + iVar6;
      goto LAB_004c30a8;
    }
  }
  ptr = (void *)(*(code *)PTR_BN_bn2dec_006a7e38)(in_a2);
  if (ptr == (void *)0x0) {
LAB_004c2e50:
    iStack_d0 = -1;
    if (in_a2 != (ASN1_OBJECT *)0x0) {
LAB_004c2e58:
      (*(code *)PTR_BN_free_006a701c)(in_a2);
      iStack_d0 = -1;
    }
    goto LAB_004c2e70;
  }
  iVar6 = (*(code *)PTR_strlen_006a9a24)(ptr);
  if (pcStack_d4 != (char *)0x0) {
    if (1 < (int)puStack_54) {
      pcStack_d4[1] = '\0';
      puStack_54 = (undefined4 *)((int)puStack_54 + -1);
      *pcStack_d4 = '.';
      pcStack_d4 = pcStack_d4 + 1;
    }
    (*(code *)PTR_BUF_strlcpy_006a6f64)(pcStack_d4,ptr,puStack_54);
    puVar8 = puStack_54;
    if (iVar6 <= (int)puStack_54) {
      pcStack_d4 = pcStack_d4 + iVar6;
      puStack_54 = (undefined4 *)((int)puStack_54 - iVar6);
      iStack_d0 = iVar6 + iStack_d0 + 1;
      CRYPTO_free(ptr);
      goto LAB_004c30a8;
    }
    puStack_54 = (undefined4 *)0x0;
    pcStack_d4 = pcStack_d4 + (int)puVar8;
  }
  iStack_d0 = iVar6 + iStack_d0 + 1;
  CRYPTO_free(ptr);
LAB_004c30a8:
  bVar3 = false;
  if (iVar4 < 1) goto code_r0x004c30b0;
  goto LAB_004c2dd4;
code_r0x004c30b0:
  if (in_a2 != (ASN1_OBJECT *)0x0) {
    (*(code *)PTR_BN_free_006a701c)(in_a2);
  }
LAB_004c2e70:
  if (iStack_84 == *(int *)puVar13) {
    return iStack_d0;
  }
  pcVar12 = (code *)PTR___stack_chk_fail_006a9ab0;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004c32f8:
  (*pcVar12)(8,0x66,0x65,"obj_dat.c",0x176);
  (*(code *)PTR_ERR_put_error_006a7f34)(8,0x68,0x65,"obj_dat.c",0x15b);
  pbVar9 = in_a2->data;
  goto LAB_004c2da0;
}

