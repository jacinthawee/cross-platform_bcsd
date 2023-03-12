
int OBJ_obj2nid(ASN1_OBJECT *o)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 *puVar4;
  ASN1_OBJECT *pAVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  void *ptr;
  int *piVar9;
  undefined4 *in_a1;
  ASN1_OBJECT *in_a2;
  int in_a3;
  byte *pbVar10;
  ASN1_OBJECT *unaff_s0;
  int unaff_s1;
  undefined1 *unaff_s3;
  undefined1 *unaff_s4;
  int unaff_s5;
  uint uVar11;
  int unaff_s6;
  uint uVar12;
  ASN1_OBJECT *unaff_s7;
  code *pcVar13;
  undefined *puVar14;
  ASN1_OBJECT *unaff_s8;
  byte *pbVar15;
  char *pcStack_cc;
  int iStack_c8;
  undefined4 uStack_b8;
  undefined *puStack_b4;
  undefined auStack_b0 [8];
  uint uStack_a8;
  undefined auStack_98 [28];
  int iStack_7c;
  ASN1_OBJECT *pAStack_78;
  int iStack_74;
  undefined *puStack_70;
  undefined1 *puStack_6c;
  undefined1 *puStack_68;
  int iStack_64;
  int iStack_60;
  ASN1_OBJECT *pAStack_5c;
  ASN1_OBJECT *pAStack_58;
  code *pcStack_54;
  undefined4 *puStack_4c;
  undefined *local_40;
  undefined4 local_34;
  ASN1_OBJECT *local_30;
  char *local_2c;
  
  puStack_70 = PTR___stack_chk_guard_006aabf0;
  local_40 = &_gp;
  local_2c = *(char **)PTR___stack_chk_guard_006aabf0;
  iVar6 = 0;
  iStack_60 = unaff_s6;
  pAStack_5c = unaff_s7;
  puVar14 = &_gp;
  if ((o != (ASN1_OBJECT *)0x0) && (iVar6 = o->nid, pAStack_5c = o, iVar6 == 0)) {
    if (added != 0) {
      in_a1 = &local_34;
      local_34 = 0;
      local_30 = o;
      iVar6 = (*(code *)PTR_lh_retrieve_006a84b0)();
      if (iVar6 != 0) {
        iVar6 = *(int *)(*(int *)(iVar6 + 4) + 8);
        puVar14 = local_40;
        goto LAB_004c5da8;
      }
    }
    unaff_s8 = (ASN1_OBJECT *)o->length;
    unaff_s5 = 0;
    unaff_s4 = obj_objs;
    unaff_s3 = nid_objs;
    unaff_s1 = 0x359;
    iStack_60 = 0x359;
    puVar14 = local_40;
    do {
      unaff_s1 = unaff_s1 >> 1;
      iVar6 = *(int *)(obj_objs + unaff_s1 * 4) * 0x18;
      unaff_s0 = (ASN1_OBJECT *)(nid_objs + iVar6);
      iVar8 = unaff_s1;
      if (unaff_s8 == *(ASN1_OBJECT **)(nid_objs + iVar6 + 0xc)) {
        in_a1 = *(undefined4 **)(nid_objs + iVar6 + 0x10);
        in_a2 = unaff_s8;
        iVar7 = (**(code **)(puVar14 + -0x5308))(o->data);
        puVar14 = local_40;
        if (-1 < iVar7) {
          if (iVar7 == 0) {
            iVar6 = *(int *)(nid_objs + iVar6 + 8);
            goto LAB_004c5da8;
          }
LAB_004c5e54:
          unaff_s5 = unaff_s1 + 1;
          iVar8 = iStack_60;
        }
      }
      else if (-1 < (int)unaff_s8 - (int)*(ASN1_OBJECT **)(nid_objs + iVar6 + 0xc))
      goto LAB_004c5e54;
      unaff_s1 = iVar8 + unaff_s5;
      iStack_60 = iVar8;
    } while (unaff_s5 < iVar8);
    iVar6 = 0;
  }
LAB_004c5da8:
  if (local_2c == *(char **)puStack_70) {
    return iVar6;
  }
  pcStack_54 = OBJ_obj2txt;
  pcStack_cc = local_2c;
  (**(code **)(puVar14 + -0x5328))();
  puVar14 = PTR___stack_chk_guard_006aabf0;
  iStack_7c = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar5 = unaff_s0;
  pAStack_78 = unaff_s0;
  iStack_74 = unaff_s1;
  puStack_6c = unaff_s3;
  puStack_68 = unaff_s4;
  iStack_64 = unaff_s5;
  pAStack_58 = unaff_s8;
  puStack_4c = in_a1;
  if ((in_a2 == (ASN1_OBJECT *)0x0) ||
     (pbVar10 = in_a2->data, pAVar5 = in_a2, pbVar10 == (byte *)0x0)) {
    in_a2 = pAVar5;
    *pcStack_cc = '\0';
    iStack_c8 = 0;
    goto LAB_004c5fc8;
  }
  if (in_a3 != 0) goto LAB_004c5efc;
  uVar12 = OBJ_obj2nid(in_a2);
  if (uVar12 == 0) {
LAB_004c6274:
    pbVar10 = in_a2->data;
  }
  else {
    if (uVar12 < 0x398) {
      iVar6 = uVar12 * 0x18;
      piVar9 = (int *)(nid_objs + iVar6);
      pcVar13 = (code *)PTR_ERR_put_error_006a9030;
      if (*(int *)(nid_objs + iVar6 + 8) == 0) goto LAB_004c6454;
      iVar6 = *(int *)(nid_objs + iVar6 + 4);
      if (iVar6 != 0) goto LAB_004c6304;
    }
    else {
      if (added != 0) {
        uStack_b8 = 3;
        puStack_b4 = auStack_b0;
        uStack_a8 = uVar12;
        iVar6 = (*(code *)PTR_lh_retrieve_006a84b0)(added,&uStack_b8);
        if (iVar6 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(8,0x66,0x65,"obj_dat.c",0x17b);
        }
        else {
          iVar6 = *(int *)(*(int *)(iVar6 + 4) + 4);
          if (iVar6 != 0) goto LAB_004c6304;
        }
      }
      if (added == 0) goto LAB_004c6274;
      uStack_b8 = 3;
      puStack_b4 = auStack_b0;
      uStack_a8 = uVar12;
      iVar6 = (*(code *)PTR_lh_retrieve_006a84b0)(added,&uStack_b8);
      if (iVar6 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(8,0x68,0x65,"obj_dat.c",0x15b);
        pbVar10 = in_a2->data;
        goto LAB_004c5efc;
      }
      piVar9 = *(int **)(iVar6 + 4);
    }
    iVar6 = *piVar9;
    if (iVar6 != 0) {
LAB_004c6304:
      if (pcStack_cc != (char *)0x0) {
        (*(code *)PTR_BUF_strlcpy_006a8064)(pcStack_cc,iVar6,puStack_4c);
      }
      iStack_c8 = (*(code *)PTR_strlen_006aab30)(iVar6);
      goto LAB_004c5fc8;
    }
    pbVar10 = in_a2->data;
  }
LAB_004c5efc:
  iVar6 = in_a2->length;
  iStack_c8 = 0;
  if (0 < iVar6) {
    iStack_c8 = 0;
    bVar3 = true;
    in_a2 = (ASN1_OBJECT *)0x0;
LAB_004c5f30:
    uVar12 = 0;
    bVar2 = false;
    pbVar15 = pbVar10;
LAB_004c5f3c:
    do {
      pbVar10 = pbVar15 + 1;
      iVar6 = iVar6 + -1;
      bVar1 = *pbVar15;
      uVar11 = (uint)bVar1;
      pbVar15 = pbVar10;
      if (iVar6 == 0) {
        if ((char)bVar1 < '\0') goto LAB_004c5fac;
        if (!bVar2) {
          uVar12 = uVar12 | uVar11;
LAB_004c616c:
          if (!bVar3) goto LAB_004c6174;
          bVar2 = false;
          if (0x4f < uVar12) goto LAB_004c6348;
          goto LAB_004c6220;
        }
LAB_004c6014:
        iVar8 = (*(code *)PTR_BN_add_word_006a81bc)(in_a2,uVar11 & 0x7f);
        if (iVar8 == 0) goto LAB_004c5fac;
        if (-1 < (char)bVar1) goto code_r0x004c6034;
      }
      else {
        if (bVar2) goto LAB_004c6014;
        uVar12 = uVar12 | uVar11 & 0x7f;
        if (-1 < (char)bVar1) goto LAB_004c616c;
        if (uVar12 < 0x2000000) {
          uVar12 = uVar12 << 7;
          goto LAB_004c5f3c;
        }
        if ((in_a2 == (ASN1_OBJECT *)0x0) &&
           (in_a2 = (ASN1_OBJECT *)(*(code *)PTR_BN_new_006a82b4)(), in_a2 == (ASN1_OBJECT *)0x0)) {
          iStack_c8 = -1;
          break;
        }
        iVar8 = (*(code *)PTR_BN_set_word_006a8820)(in_a2,uVar12);
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
    if (uVar12 < 0x50) {
LAB_004c6220:
      uVar11 = uVar12 / 0x28;
      uVar12 = uVar12 - (uVar11 * 8 + ((uint)((ulonglong)uVar12 * 0xcccccccd >> 0x20) & 0xffffffe0))
      ;
    }
    else if (bVar2) {
      iVar8 = (*(code *)PTR_BN_sub_word_006a95bc)(in_a2,0x50);
      if (iVar8 == 0) goto LAB_004c5fac;
      uVar11 = 2;
    }
    else {
LAB_004c6348:
      uVar12 = uVar12 - 0x50;
      uVar11 = 2;
    }
    if ((pcStack_cc != (char *)0x0) && (0 < (int)puStack_4c)) {
      puStack_4c = (undefined4 *)((int)puStack_4c + -1);
      *pcStack_cc = (char)uVar11 + '0';
      pcStack_cc = pcStack_cc + 1;
    }
    iStack_c8 = iStack_c8 + 1;
    if (!bVar2) {
LAB_004c6174:
      (*(code *)PTR_BIO_snprintf_006a8060)(auStack_98,0x1a,&DAT_0064d8b0,uVar12);
      iVar8 = (*(code *)PTR_strlen_006aab30)(auStack_98);
      if ((pcStack_cc != (char *)0x0) && (0 < (int)puStack_4c)) {
        (*(code *)PTR_BUF_strlcpy_006a8064)(pcStack_cc,auStack_98,puStack_4c);
        puVar4 = puStack_4c;
        if ((int)puStack_4c < iVar8) {
          puStack_4c = (undefined4 *)0x0;
          pcStack_cc = pcStack_cc + (int)puVar4;
        }
        else {
          pcStack_cc = pcStack_cc + iVar8;
          puStack_4c = (undefined4 *)((int)puStack_4c - iVar8);
        }
      }
      iStack_c8 = iStack_c8 + iVar8;
      goto LAB_004c61f4;
    }
  }
  ptr = (void *)(*(code *)PTR_BN_bn2dec_006a8f28)(in_a2);
  if (ptr == (void *)0x0) {
LAB_004c5fac:
    iStack_c8 = -1;
    if (in_a2 != (ASN1_OBJECT *)0x0) {
LAB_004c5fb4:
      (*(code *)PTR_BN_free_006a811c)(in_a2);
      iStack_c8 = -1;
    }
    goto LAB_004c5fc8;
  }
  iVar8 = (*(code *)PTR_strlen_006aab30)(ptr);
  if (pcStack_cc != (char *)0x0) {
    if (0 < (int)puStack_4c) {
      puStack_4c = (undefined4 *)((int)puStack_4c + -1);
      *pcStack_cc = '.';
      pcStack_cc = pcStack_cc + 1;
    }
    (*(code *)PTR_BUF_strlcpy_006a8064)(pcStack_cc,ptr,puStack_4c);
    puVar4 = puStack_4c;
    if (iVar8 <= (int)puStack_4c) {
      pcStack_cc = pcStack_cc + iVar8;
      puStack_4c = (undefined4 *)((int)puStack_4c - iVar8);
      iStack_c8 = iVar8 + iStack_c8 + 1;
      CRYPTO_free(ptr);
      goto LAB_004c61f4;
    }
    puStack_4c = (undefined4 *)0x0;
    pcStack_cc = pcStack_cc + (int)puVar4;
  }
  iStack_c8 = iVar8 + iStack_c8 + 1;
  CRYPTO_free(ptr);
LAB_004c61f4:
  bVar3 = false;
  if (iVar6 < 1) goto code_r0x004c61fc;
  goto LAB_004c5f30;
code_r0x004c61fc:
  if (in_a2 != (ASN1_OBJECT *)0x0) {
    (*(code *)PTR_BN_free_006a811c)(in_a2);
  }
LAB_004c5fc8:
  if (iStack_7c == *(int *)puVar14) {
    return iStack_c8;
  }
  pcVar13 = (code *)PTR___stack_chk_fail_006aabb8;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_004c6454:
  (*pcVar13)(8,0x66,0x65,"obj_dat.c",0x16a);
  (*(code *)PTR_ERR_put_error_006a9030)(8,0x68,0x65,"obj_dat.c",0x14a);
  pbVar10 = in_a2->data;
  goto LAB_004c5efc;
}

