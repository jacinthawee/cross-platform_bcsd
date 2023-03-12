
/* WARNING: Type propagation algorithm not settling */

int OBJ_obj2txt(char *buf,int buf_len,ASN1_OBJECT *a,int no_name)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  void *pvVar5;
  char cVar6;
  char *pcVar7;
  uint uVar8;
  undefined **ppuVar9;
  int iVar10;
  byte *pbVar11;
  byte *pbVar12;
  char *pcVar13;
  BIGNUM *a_00;
  uint uVar14;
  bool bVar15;
  bool bVar16;
  char *local_7c;
  char *local_78;
  char *local_74;
  undefined4 local_68;
  undefined *local_64;
  undefined auStack_60 [8];
  uint local_58;
  char acStack_48 [28];
  int local_2c;
  
  pcVar13 = buf;
  if (buf != (char *)0x0) {
    pcVar13 = (char *)0x1;
  }
  bVar15 = (int)buf < 0;
  bVar16 = buf != (char *)0x0;
  if (bVar16) {
    bVar15 = buf_len < 0;
  }
  bVar2 = buf_len != 0;
  pcVar4 = (char *)buf_len;
  if ((bVar16 && bVar2) && !bVar15) {
    pcVar4 = buf;
  }
  local_2c = __stack_chk_guard;
  cVar6 = (char)buf;
  if ((bVar16 && bVar2) && !bVar15) {
    cVar6 = '\0';
  }
  if ((bVar16 && bVar2) && !bVar15) {
    *pcVar4 = cVar6;
  }
  if ((a != (ASN1_OBJECT *)0x0) && (pbVar11 = a->data, pbVar11 != (byte *)0x0)) {
    if (no_name == 0) {
      uVar14 = OBJ_obj2nid(a);
      if (uVar14 == 0) goto LAB_0006caea;
      if (uVar14 < 0x398) {
        ppuVar9 = &nid_objs + uVar14 * 6;
        if (*(int *)(&DAT_0013fb48 + uVar14 * 0x18) == 0) {
          iVar10 = 0x176;
          goto LAB_0006cb4c;
        }
LAB_0006cbc8:
        pcVar4 = ppuVar9[1];
        if (pcVar4 == (char *)0x0) goto LAB_0006cb5c;
LAB_0006cb7e:
        if (pcVar13 != (char *)0x0) {
          BUF_strlcpy(buf,pcVar4,buf_len);
        }
        local_74 = (char *)strlen(pcVar4);
        goto LAB_0006c9e4;
      }
      if (added != (_LHASH *)0x0) {
        local_64 = auStack_60;
        local_68 = 3;
        local_58 = uVar14;
        pvVar5 = lh_retrieve(added,&local_68);
        if (pvVar5 != (void *)0x0) {
          ppuVar9 = *(undefined ***)((int)pvVar5 + 4);
          goto LAB_0006cbc8;
        }
        iVar10 = 0x184;
LAB_0006cb4c:
        ERR_put_error(8,0x66,0x65,"obj_dat.c",iVar10);
      }
LAB_0006cb5c:
      if (uVar14 < 0x398) {
        if (*(int *)(&DAT_0013fb48 + uVar14 * 0x18) == 0) {
          iVar10 = 0x15b;
LAB_0006cc52:
          ERR_put_error(8,0x68,0x65,"obj_dat.c",iVar10);
        }
        else {
          pcVar4 = (&nid_objs)[uVar14 * 6];
joined_r0x0006cc44:
          if (pcVar4 != (char *)0x0) goto LAB_0006cb7e;
        }
      }
      else if (added != (_LHASH *)0x0) {
        local_64 = auStack_60;
        local_68 = 3;
        local_58 = uVar14;
        pvVar5 = lh_retrieve(added,&local_68);
        if (pvVar5 == (void *)0x0) {
          iVar10 = 0x169;
          goto LAB_0006cc52;
        }
        pcVar4 = **(char ***)((int)pvVar5 + 4);
        goto joined_r0x0006cc44;
      }
LAB_0006caea:
      pbVar11 = a->data;
    }
    iVar10 = a->length;
    if (0 < iVar10) {
      a_00 = (BIGNUM *)0x0;
      local_74 = (char *)0x0;
      bVar15 = true;
      local_7c = buf;
      local_78 = (char *)buf_len;
      do {
        uVar14 = 0;
        pcVar13 = (char *)0x0;
        pbVar12 = pbVar11;
        while( true ) {
          pbVar11 = pbVar12 + 1;
          bVar1 = *pbVar12;
          iVar10 = iVar10 + -1;
          if ((iVar10 == 0 & bVar1 >> 7) != 0) goto joined_r0x0006cc0a;
          if (pcVar13 == (char *)0x0) {
            uVar14 = uVar14 | bVar1 & 0x7f;
          }
          else {
            iVar3 = BN_add_word(a_00,bVar1 & 0x7f);
            if (iVar3 == 0) goto joined_r0x0006cc0a;
          }
          if ((bVar1 & 0x80) == 0) break;
          uVar8 = (uint)pcVar13 ^ 1;
          if (uVar14 < 0x2000000) {
            uVar8 = 0;
          }
          pbVar12 = pbVar11;
          if (uVar8 == 0) {
            if (pcVar13 != (char *)0x0) goto LAB_0006c9ca;
            uVar14 = uVar14 << 7;
          }
          else {
            if ((a_00 == (BIGNUM *)0x0) && (a_00 = BN_new(), a_00 == (BIGNUM *)0x0))
            goto LAB_0006c9e0;
            iVar3 = BN_set_word(a_00,uVar14);
            if (iVar3 == 0) goto LAB_0006c9da;
            pcVar13 = (char *)0x1;
LAB_0006c9ca:
            iVar3 = BN_lshift(a_00,a_00,7);
            if (iVar3 == 0) goto joined_r0x0006cc0a;
          }
        }
        if (bVar15) {
          if (uVar14 < 0x50) {
            cVar6 = (char)(uVar14 / 0x28);
            uVar14 = uVar14 % 0x28;
LAB_0006ca30:
            bVar15 = local_7c != (char *)0x0;
            pcVar4 = local_7c;
            if (bVar15) {
              pcVar4 = local_78 + -1;
            }
            if ((bVar15 && local_78 != (char *)0x1) &&
                (int)pcVar4 < 0 == (bVar15 && SBORROW4((int)local_78,1))) {
              *local_7c = cVar6 + '0';
              local_7c[1] = '\0';
              local_7c = local_7c + 1;
              local_78 = local_78 + -1;
            }
            local_74 = local_74 + 1;
            goto LAB_0006ca58;
          }
          if (pcVar13 == (char *)0x0) {
            uVar14 = uVar14 - 0x50;
LAB_0006ca2e:
            cVar6 = '\x02';
            goto LAB_0006ca30;
          }
          iVar3 = BN_sub_word(a_00,0x50);
          if (iVar3 != 0) goto LAB_0006ca2e;
joined_r0x0006cc0a:
          if (a_00 != (BIGNUM *)0x0) {
LAB_0006c9da:
            BN_free(a_00);
          }
LAB_0006c9e0:
          local_74 = (char *)0xffffffff;
          goto LAB_0006c9e4;
        }
LAB_0006ca58:
        if (pcVar13 == (char *)0x0) {
          BIO_snprintf(acStack_48,0x1a,".%lu",uVar14);
          pcVar7 = (char *)strlen(acStack_48);
          pcVar4 = local_7c;
          if (local_7c != (char *)0x0) {
            pcVar4 = local_78;
          }
          if ((local_7c != (char *)0x0 && local_78 != (char *)0x0) && -1 < (int)pcVar4) {
            BUF_strlcpy(local_7c,acStack_48,(size_t)local_78);
            pcVar4 = local_78;
            if ((int)pcVar7 <= (int)local_78) {
              pcVar13 = local_78 + -(int)pcVar7;
              pcVar4 = pcVar7;
            }
            local_78 = pcVar13;
            local_7c = local_7c + (int)pcVar4;
          }
          local_74 = local_74 + (int)pcVar7;
        }
        else {
          pcVar13 = BN_bn2dec(a_00);
          if (pcVar13 == (char *)0x0) goto joined_r0x0006cc0a;
          pcVar4 = (char *)strlen(pcVar13);
          if (local_7c != (char *)0x0) {
            pcVar7 = local_78;
            if (1 < (int)local_78) {
              pcVar7 = (char *)0x0;
            }
            if (1 < (int)local_78) {
              local_7c[1] = (char)pcVar7;
              local_78 = local_78 + -1;
              *local_7c = '.';
              local_7c = local_7c + 1;
            }
            BUF_strlcpy(local_7c,pcVar13,(size_t)local_78);
            if ((int)local_78 < (int)pcVar4) {
              pcVar7 = (char *)0x0;
            }
            else {
              pcVar7 = local_78 + -(int)pcVar4;
              local_78 = pcVar4;
            }
            local_7c = local_78 + (int)local_7c;
            local_78 = pcVar7;
          }
          local_74 = local_74 + 1 + (int)pcVar4;
          CRYPTO_free(pcVar13);
        }
        if (iVar10 < 1) goto LAB_0006cc10;
        bVar15 = false;
      } while( true );
    }
  }
  local_74 = (char *)0x0;
LAB_0006c9e4:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)local_74;
LAB_0006cc10:
  if (a_00 != (BIGNUM *)0x0) {
    BN_free(a_00);
  }
  goto LAB_0006c9e4;
}

