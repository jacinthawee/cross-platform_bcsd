
int OCSP_sendreq_nbio(OCSP_RESPONSE **presp,OCSP_REQ_CTX *rctx)

{
  int iVar1;
  size_t sVar2;
  void *pvVar3;
  byte *pbVar4;
  ulong uVar5;
  ushort **ppuVar6;
  long lVar7;
  int iVar8;
  uint uVar9;
  OCSP_RESPONSE *pOVar10;
  byte bVar11;
  ushort *puVar12;
  uint uVar13;
  byte *pbVar14;
  byte *pbVar15;
  int in_GS_OFFSET;
  byte *local_28;
  byte *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar9 = *(uint *)rctx;
joined_r0x0818673d:
  uVar13 = uVar9 & 0x1000;
  if (uVar13 == 0) {
    iVar8 = BIO_read(*(BIO **)(rctx + 0xc),*(void **)(rctx + 4),*(int *)(rctx + 8));
    if (iVar8 < 1) {
      iVar8 = BIO_test_flags(*(BIO **)(rctx + 0xc),8);
      uVar13 = -(uint)(iVar8 != 0);
      goto LAB_08186771;
    }
    iVar1 = BIO_write(*(BIO **)(rctx + 0x10),*(void **)(rctx + 4),iVar8);
    if (iVar8 != iVar1) goto LAB_08186771;
    uVar9 = *(uint *)rctx;
  }
  if (uVar9 == 4) {
LAB_081867e2:
    lVar7 = BIO_ctrl(*(BIO **)(rctx + 0x10),3,0,&local_28);
    pbVar4 = local_28;
    if (*(int *)(rctx + 0x14) <= lVar7) {
      pOVar10 = d2i_OCSP_RESPONSE((OCSP_RESPONSE **)0x0,&local_28,*(int *)(rctx + 0x14));
      *presp = pOVar10;
      pbVar4 = local_28;
      if (pOVar10 != (OCSP_RESPONSE *)0x0) {
        *(undefined4 *)rctx = 0x1008;
        uVar13 = 1;
        goto LAB_08186771;
      }
      goto LAB_08186a21;
    }
  }
  else {
    if (4 < (int)uVar9) {
      if (uVar9 == 0x1007) {
LAB_08186ac8:
        lVar7 = BIO_ctrl(*(BIO **)(rctx + 0xc),0xb,0,(void *)0x0);
        if (0 < lVar7) {
          *(undefined4 *)rctx = 1;
          uVar9 = 1;
          goto joined_r0x0818673d;
        }
      }
      else {
        if (uVar9 == 0x1008) {
          uVar13 = 1;
          goto LAB_08186771;
        }
        if (uVar9 != 0x1006) goto LAB_0818676f;
        lVar7 = BIO_ctrl(*(BIO **)(rctx + 0x10),3,0,&local_28);
        iVar8 = BIO_write(*(BIO **)(rctx + 0xc),local_28 + (lVar7 - *(int *)(rctx + 0x14)),
                          *(int *)(rctx + 0x14));
        if (0 < iVar8) {
          iVar1 = *(int *)(rctx + 0x14);
          *(int *)(rctx + 0x14) = iVar1 - iVar8;
          pbVar4 = local_28;
          if (iVar1 - iVar8 != 0) goto LAB_081867fd;
          *(undefined4 *)rctx = 0x1007;
          BIO_ctrl(*(BIO **)(rctx + 0x10),1,0,(void *)0x0);
          goto LAB_08186ac8;
        }
      }
      uVar13 = 0xffffffff;
      iVar8 = BIO_test_flags(*(BIO **)(rctx + 0xc),8);
      pbVar4 = local_28;
      if (iVar8 != 0) goto LAB_08186771;
LAB_08186a21:
      local_28 = pbVar4;
      *(undefined4 *)rctx = 0x1000;
LAB_0818676f:
      uVar13 = 0;
LAB_08186771:
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        return uVar13;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    if ((int)uVar9 < 1) goto LAB_0818676f;
    if ((int)uVar9 < 3) {
LAB_08186852:
      do {
        sVar2 = BIO_ctrl(*(BIO **)(rctx + 0x10),3,0,&local_28);
        if (((int)sVar2 < 1) || (pvVar3 = memchr(local_28,10,sVar2), pvVar3 == (void *)0x0))
        goto LAB_08186b40;
        iVar8 = BIO_gets(*(BIO **)(rctx + 0x10),*(char **)(rctx + 4),*(int *)(rctx + 8));
        if (iVar8 < 1) {
          iVar8 = BIO_test_flags(*(BIO **)(rctx + 0x10),8);
          pbVar4 = local_28;
          if (iVar8 == 0) goto LAB_08186a21;
          uVar9 = *(uint *)rctx;
          goto joined_r0x0818673d;
        }
        pbVar4 = local_28;
        if (iVar8 == *(int *)(rctx + 8)) goto LAB_08186a21;
        if (*(int *)rctx == 1) {
          pbVar15 = *(byte **)(rctx + 4);
          bVar11 = *pbVar15;
          if (bVar11 == 0) {
LAB_08186a66:
            iVar8 = 200;
LAB_08186b22:
            ERR_put_error(0x27,0x76,0x73,"ocsp_ht.c",iVar8);
            *(undefined4 *)rctx = 0x1000;
            goto LAB_0818676f;
          }
          ppuVar6 = __ctype_b_loc();
          puVar12 = *ppuVar6;
          while (uVar9 = (uint)bVar11, (*(byte *)((int)puVar12 + uVar9 * 2 + 1) & 0x20) == 0) {
            pbVar15 = pbVar15 + 1;
            bVar11 = *pbVar15;
            if (bVar11 == 0) goto LAB_08186a66;
          }
          while (pbVar14 = pbVar15, (*(byte *)((int)puVar12 + uVar9 * 2 + 1) & 0x20) != 0) {
            pbVar15 = pbVar15 + 1;
            uVar9 = (uint)*pbVar15;
            if (*pbVar15 == 0) {
              iVar8 = 0xd3;
              goto LAB_08186b22;
            }
          }
          while ((*(byte *)((int)puVar12 + uVar9 * 2 + 1) & 0x20) == 0) {
            bVar11 = pbVar14[1];
            uVar9 = (uint)bVar11;
            pbVar14 = pbVar14 + 1;
            if (bVar11 == 0) {
              iVar8 = 0xde;
              goto LAB_08186b22;
            }
          }
          *pbVar14 = 0;
          uVar5 = strtoul((char *)pbVar15,(char **)&local_24,10);
          pbVar4 = local_28;
          if (*local_24 != 0) goto LAB_08186a21;
          bVar11 = pbVar14[1];
          pbVar14 = pbVar14 + 1;
          if (bVar11 != 0) {
            puVar12 = *ppuVar6;
LAB_0818697a:
            if ((*(byte *)((int)puVar12 + (uint)bVar11 * 2 + 1) & 0x20) != 0) goto LAB_08186970;
            sVar2 = strlen((char *)pbVar14);
            local_24 = pbVar14 + (sVar2 - 1);
            while ((*(byte *)((int)puVar12 + (uint)*local_24 * 2 + 1) & 0x20) != 0) {
              *local_24 = 0;
              local_24 = local_24 + -1;
              puVar12 = *ppuVar6;
            }
          }
LAB_081869ce:
          if (uVar5 != 200) {
            ERR_put_error(0x27,0x76,0x72,"ocsp_ht.c",0xfa);
            if (*pbVar14 == 0) {
              ERR_add_error_data(2,"Code=",pbVar15);
              pbVar4 = local_28;
            }
            else {
              ERR_add_error_data(4,"Code=",pbVar15,",Reason=",pbVar14);
              pbVar4 = local_28;
            }
            goto LAB_08186a21;
          }
          *(undefined4 *)rctx = 2;
        }
        else {
          local_28 = *(byte **)(rctx + 4);
          bVar11 = *local_28;
          if (bVar11 == 0) {
LAB_081868f7:
            *(undefined4 *)rctx = 3;
            break;
          }
          if ((bVar11 == 0xd) || (bVar11 == 10)) {
            pbVar4 = local_28 + 1;
            do {
              bVar11 = *pbVar4;
              local_28 = pbVar4;
              while( true ) {
                if (bVar11 == 0) goto LAB_081868f7;
                pbVar4 = local_28 + 1;
                if (bVar11 == 0xd) break;
                if (bVar11 != 10) goto LAB_08186852;
                bVar11 = *pbVar4;
                local_28 = pbVar4;
              }
            } while( true );
          }
        }
      } while( true );
    }
    lVar7 = BIO_ctrl(*(BIO **)(rctx + 0x10),3,0,&local_28);
    pbVar4 = local_28;
    if (1 < lVar7) {
      pbVar4 = local_28 + 1;
      if (*local_28 != 0x30) goto LAB_08186a21;
      bVar11 = local_28[1];
      if ((char)bVar11 < '\0') {
        if (lVar7 < 6) goto LAB_081867fd;
        uVar9 = bVar11 & 0x7f;
        if (3 < (byte)((char)uVar9 - 1U)) goto LAB_08186a21;
        pbVar4 = local_28 + 2;
        uVar13 = 0;
        pbVar15 = pbVar4;
        do {
          local_28 = pbVar15 + 1;
          *(uint *)(rctx + 0x14) = uVar13 << 8;
          uVar13 = uVar13 << 8 | (uint)*pbVar15;
          *(uint *)(rctx + 0x14) = uVar13;
          pbVar15 = local_28;
        } while (local_28 != pbVar4 + uVar9);
        pbVar4 = local_28;
        if (0x19000 < uVar13) goto LAB_08186a21;
        *(uint *)(rctx + 0x14) = uVar13 + 2 + uVar9;
      }
      else {
        *(uint *)(rctx + 0x14) = bVar11 + 2;
        local_28 = pbVar4;
      }
      *(undefined4 *)rctx = 4;
      goto LAB_081867e2;
    }
  }
LAB_081867fd:
  local_28 = pbVar4;
  uVar9 = *(uint *)rctx;
  goto joined_r0x0818673d;
LAB_08186b40:
  pbVar4 = local_28;
  if (*(int *)(rctx + 8) <= (int)sVar2) goto LAB_08186a21;
  uVar9 = *(uint *)rctx;
  goto joined_r0x0818673d;
LAB_08186970:
  pbVar14 = pbVar14 + 1;
  bVar11 = *pbVar14;
  if (bVar11 == 0) goto LAB_081869ce;
  goto LAB_0818697a;
}

