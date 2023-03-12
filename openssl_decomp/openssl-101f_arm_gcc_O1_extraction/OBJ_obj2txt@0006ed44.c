
/* WARNING: Type propagation algorithm not settling */

int OBJ_obj2txt(char *buf,int buf_len,ASN1_OBJECT *a,int no_name)

{
  byte bVar1;
  char *pcVar2;
  bool bVar3;
  int iVar4;
  size_t sVar5;
  char *pcVar6;
  void *pvVar7;
  char cVar8;
  uint uVar9;
  undefined **ppuVar10;
  int iVar11;
  byte *pbVar12;
  byte *pbVar13;
  BIGNUM *a_00;
  uint uVar14;
  char *pcVar15;
  char *local_7c;
  char *local_78;
  char *local_74;
  undefined4 local_68;
  undefined *local_64;
  undefined auStack_60 [8];
  uint local_58;
  char acStack_48 [28];
  int local_2c;
  
  local_2c = __TMC_END__;
  if ((a == (ASN1_OBJECT *)0x0) || (pbVar12 = a->data, pbVar12 == (byte *)0x0)) {
    local_78 = (char *)0x0;
    *buf = '\0';
    goto LAB_0006ee00;
  }
  if (no_name == 0) {
    uVar14 = OBJ_obj2nid(a);
    if (uVar14 == 0) goto LAB_0006eef8;
    if (uVar14 < 0x398) {
      ppuVar10 = &nid_objs + uVar14 * 6;
      if (*(int *)(&DAT_00140f90 + uVar14 * 0x18) == 0) {
        iVar11 = 0x16a;
        goto LAB_0006efb0;
      }
LAB_0006ef5e:
      pcVar15 = ppuVar10[1];
      if (pcVar15 == (char *)0x0) goto LAB_0006efc0;
LAB_0006ef62:
      if (buf != (char *)0x0) {
        BUF_strlcpy(buf,pcVar15,buf_len);
      }
      local_78 = (char *)strlen(pcVar15);
      goto LAB_0006ee00;
    }
    if (added != (_LHASH *)0x0) {
      local_64 = auStack_60;
      local_68 = 3;
      local_58 = uVar14;
      pvVar7 = lh_retrieve(added,&local_68);
      if (pvVar7 != (void *)0x0) {
        ppuVar10 = *(undefined ***)((int)pvVar7 + 4);
        goto LAB_0006ef5e;
      }
      iVar11 = 0x17b;
LAB_0006efb0:
      ERR_put_error(8,0x66,0x65,"obj_dat.c",iVar11);
    }
LAB_0006efc0:
    if (uVar14 < 0x398) {
      if (*(int *)(&DAT_00140f90 + uVar14 * 0x18) == 0) {
        iVar11 = 0x14a;
LAB_0006f070:
        ERR_put_error(8,0x68,0x65,"obj_dat.c",iVar11);
      }
      else {
        pcVar15 = (&nid_objs)[uVar14 * 6];
joined_r0x0006f05e:
        if (pcVar15 != (char *)0x0) goto LAB_0006ef62;
      }
    }
    else if (added != (_LHASH *)0x0) {
      local_64 = auStack_60;
      local_68 = 3;
      local_58 = uVar14;
      pvVar7 = lh_retrieve(added,&local_68);
      if (pvVar7 == (void *)0x0) {
        iVar11 = 0x15b;
        goto LAB_0006f070;
      }
      pcVar15 = **(char ***)((int)pvVar7 + 4);
      goto joined_r0x0006f05e;
    }
LAB_0006eef8:
    pbVar12 = a->data;
  }
  iVar11 = a->length;
  if (0 < iVar11) {
    local_78 = (char *)0x0;
    a_00 = (BIGNUM *)0x0;
    bVar3 = true;
    local_7c = (char *)buf_len;
    local_74 = buf;
    do {
      uVar14 = 0;
      pcVar15 = (char *)0x0;
      pbVar13 = pbVar12;
      while( true ) {
        pbVar12 = pbVar13 + 1;
        bVar1 = *pbVar13;
        iVar11 = iVar11 + -1;
        if ((iVar11 == 0 & bVar1 >> 7) != 0) goto joined_r0x0006f020;
        if (pcVar15 == (char *)0x0) {
          uVar14 = uVar14 | bVar1 & 0x7f;
        }
        else {
          iVar4 = BN_add_word(a_00,bVar1 & 0x7f);
          if (iVar4 == 0) goto joined_r0x0006f020;
        }
        if ((bVar1 & 0x80) == 0) break;
        uVar9 = (uint)pcVar15 ^ 1;
        if (uVar14 < 0x2000000) {
          uVar9 = 0;
        }
        pbVar13 = pbVar12;
        if (uVar9 == 0) {
          if (pcVar15 != (char *)0x0) goto LAB_0006ede6;
          uVar14 = uVar14 << 7;
        }
        else {
          if ((a_00 == (BIGNUM *)0x0) && (a_00 = BN_new(), a_00 == (BIGNUM *)0x0))
          goto LAB_0006edfc;
          iVar4 = BN_set_word(a_00,uVar14);
          if (iVar4 == 0) goto LAB_0006edf6;
          pcVar15 = (char *)0x1;
LAB_0006ede6:
          iVar4 = BN_lshift(a_00,a_00,7);
          if (iVar4 == 0) goto joined_r0x0006f020;
        }
      }
      if (bVar3) {
        if (uVar14 < 0x50) {
          cVar8 = (char)(uVar14 / 0x28);
          uVar14 = uVar14 % 0x28;
LAB_0006ee4c:
          pcVar2 = local_74;
          if (local_74 != (char *)0x0) {
            pcVar2 = local_7c;
          }
          if ((local_74 != (char *)0x0 && local_7c != (char *)0x0) && -1 < (int)pcVar2) {
            local_7c = local_7c + -1;
            *local_74 = cVar8 + '0';
            local_74 = local_74 + 1;
          }
          local_78 = local_78 + 1;
          goto LAB_0006ee6a;
        }
        if (pcVar15 == (char *)0x0) {
          uVar14 = uVar14 - 0x50;
LAB_0006ee4a:
          cVar8 = '\x02';
          goto LAB_0006ee4c;
        }
        iVar4 = BN_sub_word(a_00,0x50);
        if (iVar4 != 0) goto LAB_0006ee4a;
joined_r0x0006f020:
        if (a_00 != (BIGNUM *)0x0) {
LAB_0006edf6:
          BN_free(a_00);
        }
LAB_0006edfc:
        local_78 = (char *)0xffffffff;
        goto LAB_0006ee00;
      }
LAB_0006ee6a:
      if (pcVar15 == (char *)0x0) {
        BIO_snprintf(acStack_48,0x1a,".%lu",uVar14);
        pcVar6 = (char *)strlen(acStack_48);
        pcVar2 = local_74;
        if (local_74 != (char *)0x0) {
          pcVar2 = local_7c;
        }
        if ((local_74 != (char *)0x0 && local_7c != (char *)0x0) && -1 < (int)pcVar2) {
          BUF_strlcpy(local_74,acStack_48,(size_t)local_7c);
          pcVar2 = local_7c;
          if ((int)pcVar6 <= (int)local_7c) {
            pcVar15 = local_7c + -(int)pcVar6;
            pcVar2 = pcVar6;
          }
          local_7c = pcVar15;
          local_74 = local_74 + (int)pcVar2;
        }
      }
      else {
        pcVar15 = BN_bn2dec(a_00);
        if (pcVar15 == (char *)0x0) goto joined_r0x0006f020;
        sVar5 = strlen(pcVar15);
        if (local_74 != (char *)0x0) {
          if (0 < (int)local_7c) {
            local_7c = local_7c + -1;
            *local_74 = '.';
            local_74 = local_74 + 1;
          }
          BUF_strlcpy(local_74,pcVar15,(size_t)local_7c);
          if ((int)local_7c < (int)sVar5) {
            local_74 = local_7c + (int)local_74;
            local_7c = (char *)0x0;
          }
          else {
            local_74 = local_74 + sVar5;
            local_7c = local_7c + -sVar5;
          }
        }
        pcVar6 = (char *)(sVar5 + 1);
        CRYPTO_free(pcVar15);
      }
      local_78 = local_78 + (int)pcVar6;
      if (iVar11 < 1) goto LAB_0006f02a;
      bVar3 = false;
    } while( true );
  }
  local_78 = (char *)0x0;
LAB_0006ee00:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)local_78;
LAB_0006f02a:
  if (a_00 != (BIGNUM *)0x0) {
    BN_free(a_00);
  }
  goto LAB_0006ee00;
}

