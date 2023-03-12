
int OBJ_obj2txt(char *buf,int buf_len,ASN1_OBJECT *a,int no_name)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  undefined *puVar4;
  int iVar5;
  void *ptr;
  int iVar6;
  int *piVar7;
  byte *pbVar8;
  ASN1_OBJECT *unaff_s0;
  int iVar9;
  uint uVar10;
  uint uVar11;
  code *pcVar12;
  byte *pbVar13;
  int local_res4;
  char *local_7c;
  int local_78;
  undefined4 local_68;
  undefined *local_64;
  undefined auStack_60 [8];
  uint local_58;
  undefined auStack_48 [28];
  int local_2c;
  
  puVar4 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_7c = buf;
  local_res4 = buf_len;
  if ((a == (ASN1_OBJECT *)0x0) || (pbVar8 = a->data, unaff_s0 = a, pbVar8 == (byte *)0x0)) {
    a = unaff_s0;
    *buf = '\0';
    local_78 = 0;
    goto LAB_004c5fc8;
  }
  if (no_name != 0) goto LAB_004c5efc;
  uVar11 = OBJ_obj2nid(a);
  if (uVar11 == 0) {
LAB_004c6274:
    pbVar8 = a->data;
  }
  else {
    if (uVar11 < 0x398) {
      iVar9 = uVar11 * 0x18;
      piVar7 = (int *)(nid_objs + iVar9);
      pcVar12 = (code *)PTR_ERR_put_error_006a9030;
      if (*(int *)(nid_objs + iVar9 + 8) == 0) goto LAB_004c6454;
      iVar9 = *(int *)(nid_objs + iVar9 + 4);
      if (iVar9 != 0) goto LAB_004c6304;
    }
    else {
      if (added != 0) {
        local_68 = 3;
        local_64 = auStack_60;
        local_58 = uVar11;
        iVar9 = (*(code *)PTR_lh_retrieve_006a84b0)(added,&local_68);
        if (iVar9 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(8,0x66,0x65,"obj_dat.c",0x17b);
        }
        else {
          iVar9 = *(int *)(*(int *)(iVar9 + 4) + 4);
          if (iVar9 != 0) goto LAB_004c6304;
        }
      }
      if (added == 0) goto LAB_004c6274;
      local_68 = 3;
      local_64 = auStack_60;
      local_58 = uVar11;
      iVar9 = (*(code *)PTR_lh_retrieve_006a84b0)(added,&local_68);
      if (iVar9 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(8,0x68,0x65,"obj_dat.c",0x15b);
        pbVar8 = a->data;
        goto LAB_004c5efc;
      }
      piVar7 = *(int **)(iVar9 + 4);
    }
    iVar9 = *piVar7;
    if (iVar9 != 0) {
LAB_004c6304:
      if (buf != (char *)0x0) {
        (*(code *)PTR_BUF_strlcpy_006a8064)(buf,iVar9,buf_len);
      }
      local_78 = (*(code *)PTR_strlen_006aab30)(iVar9);
      goto LAB_004c5fc8;
    }
    pbVar8 = a->data;
  }
LAB_004c5efc:
  iVar9 = a->length;
  local_78 = 0;
  if (0 < iVar9) {
    local_78 = 0;
    bVar3 = true;
    a = (ASN1_OBJECT *)0x0;
LAB_004c5f30:
    uVar11 = 0;
    bVar2 = false;
    pbVar13 = pbVar8;
LAB_004c5f3c:
    do {
      pbVar8 = pbVar13 + 1;
      iVar9 = iVar9 + -1;
      bVar1 = *pbVar13;
      uVar10 = (uint)bVar1;
      pbVar13 = pbVar8;
      if (iVar9 == 0) {
        if ((char)bVar1 < '\0') goto LAB_004c5fac;
        if (!bVar2) {
          uVar11 = uVar11 | uVar10;
LAB_004c616c:
          if (!bVar3) goto LAB_004c6174;
          bVar2 = false;
          if (0x4f < uVar11) goto LAB_004c6348;
          goto LAB_004c6220;
        }
LAB_004c6014:
        iVar5 = (*(code *)PTR_BN_add_word_006a81bc)(a,uVar10 & 0x7f);
        if (iVar5 == 0) goto LAB_004c5fac;
        if (-1 < (char)bVar1) goto code_r0x004c6034;
      }
      else {
        if (bVar2) goto LAB_004c6014;
        uVar11 = uVar11 | uVar10 & 0x7f;
        if (-1 < (char)bVar1) goto LAB_004c616c;
        if (uVar11 < 0x2000000) {
          uVar11 = uVar11 << 7;
          goto LAB_004c5f3c;
        }
        if ((a == (ASN1_OBJECT *)0x0) &&
           (a = (ASN1_OBJECT *)(*(code *)PTR_BN_new_006a82b4)(), a == (ASN1_OBJECT *)0x0)) {
          local_78 = -1;
          break;
        }
        iVar5 = (*(code *)PTR_BN_set_word_006a8820)(a,uVar11);
        if (iVar5 == 0) goto LAB_004c5fb4;
        bVar2 = true;
      }
      iVar5 = (*(code *)PTR_BN_lshift_006a95b8)(a,a,7);
      if (iVar5 == 0) goto LAB_004c5fac;
    } while( true );
  }
  goto LAB_004c5fc8;
code_r0x004c6034:
  if (bVar3) {
    if (uVar11 < 0x50) {
LAB_004c6220:
      uVar10 = uVar11 / 0x28;
      uVar11 = uVar11 - (uVar10 * 8 + ((uint)((ulonglong)uVar11 * 0xcccccccd >> 0x20) & 0xffffffe0))
      ;
    }
    else if (bVar2) {
      iVar5 = (*(code *)PTR_BN_sub_word_006a95bc)(a,0x50);
      if (iVar5 == 0) goto LAB_004c5fac;
      uVar10 = 2;
    }
    else {
LAB_004c6348:
      uVar11 = uVar11 - 0x50;
      uVar10 = 2;
    }
    if ((local_7c != (char *)0x0) && (0 < local_res4)) {
      local_res4 = local_res4 + -1;
      *local_7c = (char)uVar10 + '0';
      local_7c = local_7c + 1;
    }
    local_78 = local_78 + 1;
    if (!bVar2) {
LAB_004c6174:
      iVar5 = local_res4;
      (*(code *)PTR_BIO_snprintf_006a8060)(auStack_48,0x1a,&DAT_0064d898,uVar11);
      iVar6 = (*(code *)PTR_strlen_006aab30)(auStack_48);
      if ((local_7c != (char *)0x0) && (0 < local_res4)) {
        (*(code *)PTR_BUF_strlcpy_006a8064)(local_7c,auStack_48,local_res4);
        if (local_res4 < iVar6) {
          local_res4 = 0;
          local_7c = local_7c + iVar5;
        }
        else {
          local_7c = local_7c + iVar6;
          local_res4 = local_res4 - iVar6;
        }
      }
      local_78 = local_78 + iVar6;
      goto LAB_004c61f4;
    }
  }
  ptr = (void *)(*(code *)PTR_BN_bn2dec_006a8f28)(a);
  if (ptr == (void *)0x0) {
LAB_004c5fac:
    local_78 = -1;
    if (a != (ASN1_OBJECT *)0x0) {
LAB_004c5fb4:
      (*(code *)PTR_BN_free_006a811c)(a);
      local_78 = -1;
    }
    goto LAB_004c5fc8;
  }
  iVar5 = (*(code *)PTR_strlen_006aab30)(ptr);
  if (local_7c != (char *)0x0) {
    if (0 < local_res4) {
      local_res4 = local_res4 + -1;
      *local_7c = '.';
      local_7c = local_7c + 1;
    }
    iVar6 = local_res4;
    (*(code *)PTR_BUF_strlcpy_006a8064)(local_7c,ptr,local_res4);
    if (iVar5 <= local_res4) {
      local_7c = local_7c + iVar5;
      local_res4 = local_res4 - iVar5;
      local_78 = iVar5 + local_78 + 1;
      CRYPTO_free(ptr);
      goto LAB_004c61f4;
    }
    local_res4 = 0;
    local_7c = local_7c + iVar6;
  }
  local_78 = iVar5 + local_78 + 1;
  CRYPTO_free(ptr);
LAB_004c61f4:
  bVar3 = false;
  if (iVar9 < 1) goto code_r0x004c61fc;
  goto LAB_004c5f30;
code_r0x004c61fc:
  if (a != (ASN1_OBJECT *)0x0) {
    (*(code *)PTR_BN_free_006a811c)(a);
  }
LAB_004c5fc8:
  if (local_2c == *(int *)puVar4) {
    return local_78;
  }
  pcVar12 = (code *)PTR___stack_chk_fail_006aabb8;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_004c6454:
  (*pcVar12)(8,0x66,0x65,"obj_dat.c",0x16a);
  (*(code *)PTR_ERR_put_error_006a9030)(8,0x68,0x65,"obj_dat.c",0x14a);
  pbVar8 = a->data;
  goto LAB_004c5efc;
}

