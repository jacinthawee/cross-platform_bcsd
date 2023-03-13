
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
  uint uVar9;
  uint uVar10;
  int iVar11;
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
  
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((buf != (char *)0x0) && (0 < buf_len)) {
    *buf = '\0';
  }
  local_78 = 0;
  local_res4 = buf_len;
  local_7c = buf;
  if (a == (ASN1_OBJECT *)0x0) goto LAB_004c2e70;
  pbVar8 = a->data;
  if (pbVar8 == (byte *)0x0) goto LAB_004c2e70;
  if (no_name != 0) goto LAB_004c2da0;
  uVar10 = OBJ_obj2nid(a);
  if (uVar10 == 0) {
LAB_004c3128:
    pbVar8 = a->data;
  }
  else {
    if (uVar10 < 0x398) {
      iVar11 = uVar10 * 0x18;
      piVar7 = (int *)(nid_objs + iVar11);
      pcVar12 = (code *)PTR_ERR_put_error_006a7f34;
      if (*(int *)(nid_objs + iVar11 + 8) == 0) goto LAB_004c32f8;
      iVar11 = *(int *)(nid_objs + iVar11 + 4);
      if (iVar11 != 0) goto LAB_004c31bc;
    }
    else {
      if (added != 0) {
        local_68 = 3;
        local_64 = auStack_60;
        local_58 = uVar10;
        iVar11 = (*(code *)PTR_lh_retrieve_006a73b0)(added,&local_68);
        if (iVar11 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(8,0x66,0x65,"obj_dat.c",0x184);
        }
        else {
          iVar11 = *(int *)(*(int *)(iVar11 + 4) + 4);
          if (iVar11 != 0) goto LAB_004c31bc;
        }
      }
      if (added == 0) goto LAB_004c3128;
      local_68 = 3;
      local_64 = auStack_60;
      local_58 = uVar10;
      iVar11 = (*(code *)PTR_lh_retrieve_006a73b0)(added,&local_68);
      if (iVar11 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(8,0x68,0x65,"obj_dat.c",0x169);
        pbVar8 = a->data;
        goto LAB_004c2da0;
      }
      piVar7 = *(int **)(iVar11 + 4);
    }
    iVar11 = *piVar7;
    if (iVar11 != 0) {
LAB_004c31bc:
      if (buf != (char *)0x0) {
        (*(code *)PTR_BUF_strlcpy_006a6f64)(buf,iVar11,buf_len);
      }
      local_78 = (*(code *)PTR_strlen_006a9a24)(iVar11);
      goto LAB_004c2e70;
    }
    pbVar8 = a->data;
  }
LAB_004c2da0:
  iVar11 = a->length;
  local_78 = 0;
  if (0 < iVar11) {
    local_78 = 0;
    bVar3 = true;
    a = (ASN1_OBJECT *)0x0;
LAB_004c2dd4:
    uVar10 = 0;
    bVar2 = false;
    pbVar13 = pbVar8;
LAB_004c2de0:
    do {
      pbVar8 = pbVar13 + 1;
      iVar11 = iVar11 + -1;
      bVar1 = *pbVar13;
      uVar9 = (uint)bVar1;
      pbVar13 = pbVar8;
      if (iVar11 == 0) {
        if ((char)bVar1 < '\0') goto LAB_004c2e50;
        if (!bVar2) {
          uVar10 = uVar10 | uVar9;
LAB_004c3020:
          if (!bVar3) goto LAB_004c3028;
          bVar2 = false;
          if (0x4f < uVar10) goto LAB_004c31ec;
          goto LAB_004c30d4;
        }
LAB_004c2eb8:
        iVar5 = (*(code *)PTR_BN_add_word_006a70bc)(a,uVar9 & 0x7f);
        if (iVar5 == 0) goto LAB_004c2e50;
        if (-1 < (char)bVar1) goto code_r0x004c2ed8;
      }
      else {
        if (bVar2) goto LAB_004c2eb8;
        uVar10 = uVar10 | uVar9 & 0x7f;
        if (-1 < (char)bVar1) goto LAB_004c3020;
        if (uVar10 < 0x2000000) {
          uVar10 = uVar10 << 7;
          goto LAB_004c2de0;
        }
        if ((a == (ASN1_OBJECT *)0x0) &&
           (a = (ASN1_OBJECT *)(*(code *)PTR_BN_new_006a71b4)(), a == (ASN1_OBJECT *)0x0)) {
          local_78 = -1;
          break;
        }
        iVar5 = (*(code *)PTR_BN_set_word_006a7730)(a,uVar10);
        if (iVar5 == 0) goto LAB_004c2e58;
        bVar2 = true;
      }
      iVar5 = (*(code *)PTR_BN_lshift_006a8498)(a,a,7);
      if (iVar5 == 0) goto LAB_004c2e50;
    } while( true );
  }
  goto LAB_004c2e70;
code_r0x004c2ed8:
  if (bVar3) {
    if (uVar10 < 0x50) {
LAB_004c30d4:
      uVar9 = uVar10 / 0x28;
      uVar10 = uVar10 - (uVar9 * 8 + ((uint)((ulonglong)uVar10 * 0xcccccccd >> 0x20) & 0xffffffe0));
    }
    else if (bVar2) {
      iVar5 = (*(code *)PTR_BN_sub_word_006a849c)(a,0x50);
      if (iVar5 == 0) goto LAB_004c2e50;
      uVar9 = 2;
    }
    else {
LAB_004c31ec:
      uVar10 = uVar10 - 0x50;
      uVar9 = 2;
    }
    if ((local_7c != (char *)0x0) && (1 < local_res4)) {
      local_7c[1] = '\0';
      local_res4 = local_res4 + -1;
      *local_7c = (char)uVar9 + '0';
      local_7c = local_7c + 1;
    }
    local_78 = local_78 + 1;
    if (!bVar2) {
LAB_004c3028:
      iVar5 = local_res4;
      (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_48,0x1a,&DAT_0064cf14,uVar10);
      iVar6 = (*(code *)PTR_strlen_006a9a24)(auStack_48);
      if ((local_7c != (char *)0x0) && (0 < local_res4)) {
        (*(code *)PTR_BUF_strlcpy_006a6f64)(local_7c,auStack_48,local_res4);
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
      goto LAB_004c30a8;
    }
  }
  ptr = (void *)(*(code *)PTR_BN_bn2dec_006a7e38)(a);
  if (ptr == (void *)0x0) {
LAB_004c2e50:
    local_78 = -1;
    if (a != (ASN1_OBJECT *)0x0) {
LAB_004c2e58:
      (*(code *)PTR_BN_free_006a701c)(a);
      local_78 = -1;
    }
    goto LAB_004c2e70;
  }
  iVar5 = (*(code *)PTR_strlen_006a9a24)(ptr);
  if (local_7c != (char *)0x0) {
    if (1 < local_res4) {
      local_7c[1] = '\0';
      local_res4 = local_res4 + -1;
      *local_7c = '.';
      local_7c = local_7c + 1;
    }
    iVar6 = local_res4;
    (*(code *)PTR_BUF_strlcpy_006a6f64)(local_7c,ptr,local_res4);
    if (iVar5 <= local_res4) {
      local_7c = local_7c + iVar5;
      local_res4 = local_res4 - iVar5;
      local_78 = iVar5 + local_78 + 1;
      CRYPTO_free(ptr);
      goto LAB_004c30a8;
    }
    local_res4 = 0;
    local_7c = local_7c + iVar6;
  }
  local_78 = iVar5 + local_78 + 1;
  CRYPTO_free(ptr);
LAB_004c30a8:
  bVar3 = false;
  if (iVar11 < 1) goto code_r0x004c30b0;
  goto LAB_004c2dd4;
code_r0x004c30b0:
  if (a != (ASN1_OBJECT *)0x0) {
    (*(code *)PTR_BN_free_006a701c)(a);
  }
LAB_004c2e70:
  if (local_2c == *(int *)puVar4) {
    return local_78;
  }
  pcVar12 = (code *)PTR___stack_chk_fail_006a9ab0;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004c32f8:
  (*pcVar12)(8,0x66,0x65,"obj_dat.c",0x176);
  (*(code *)PTR_ERR_put_error_006a7f34)(8,0x68,0x65,"obj_dat.c",0x15b);
  pbVar8 = a->data;
  goto LAB_004c2da0;
}

