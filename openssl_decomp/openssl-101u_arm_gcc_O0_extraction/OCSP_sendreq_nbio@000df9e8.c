
int OCSP_sendreq_nbio(OCSP_RESPONSE **presp,OCSP_REQ_CTX *rctx)

{
  byte bVar1;
  size_t sVar2;
  void *pvVar3;
  ulong uVar4;
  ushort **ppuVar5;
  long lVar6;
  int iVar7;
  OCSP_RESPONSE *pOVar8;
  byte *pbVar9;
  ushort *puVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  byte *pbVar14;
  bool bVar15;
  byte *local_30;
  byte *local_2c [2];
  
  uVar12 = *(uint *)rctx;
joined_r0x000dfa0a:
  do {
    while( true ) {
      if ((uVar12 & 0x1000) == 0) {
        iVar7 = BIO_read(*(BIO **)(rctx + 0xc),*(void **)(rctx + 4),*(int *)(rctx + 8));
        if (iVar7 < 1) {
          iVar7 = BIO_test_flags(*(BIO **)(rctx + 0xc),8);
          if (iVar7 != 0) {
            return -1;
          }
          return 0;
        }
        iVar13 = BIO_write(*(BIO **)(rctx + 0x10),*(void **)(rctx + 4),iVar7);
        if (iVar13 != iVar7) {
          return 0;
        }
        uVar12 = *(uint *)rctx;
      }
      if (uVar12 != 4) break;
LAB_000dfa70:
      lVar6 = BIO_ctrl(*(BIO **)(rctx + 0x10),3,0,&local_30);
      pbVar9 = local_30;
      if (*(long *)(rctx + 0x14) <= lVar6) {
        pOVar8 = d2i_OCSP_RESPONSE((OCSP_RESPONSE **)0x0,&local_30,*(long *)(rctx + 0x14));
        *presp = pOVar8;
        if (pOVar8 != (OCSP_RESPONSE *)0x0) {
          *(undefined4 *)rctx = 0x1008;
          return 1;
        }
        goto LAB_000dfbd4;
      }
LAB_000dfa84:
      local_30 = pbVar9;
      uVar12 = *(uint *)rctx;
    }
    if ((int)uVar12 < 5) {
      if ((int)uVar12 < 1) {
        return 0;
      }
      if (2 < (int)uVar12) {
LAB_000dfa40:
        lVar6 = BIO_ctrl(*(BIO **)(rctx + 0x10),3,0,&local_30);
        pbVar9 = local_30;
        if (lVar6 < 2) goto LAB_000dfa84;
        if (*local_30 != 0x30) goto LAB_000dfbd4;
        uVar12 = (uint)local_30[1];
        bVar15 = -1 < (int)(uVar12 << 0x18);
        if (bVar15) {
          uVar12 = uVar12 + 2;
        }
        if (bVar15) {
          *(uint *)(rctx + 0x14) = uVar12;
          local_30 = local_30 + 1;
        }
        else {
          pbVar9 = local_30 + 1;
          if (lVar6 < 6) goto LAB_000dfa84;
          uVar12 = uVar12 & 0x7f;
          if (3 < uVar12 - 1) goto LAB_000dfbd4;
          pbVar14 = local_30 + 2;
          uVar11 = 0;
          pbVar9 = pbVar14;
          do {
            local_30 = pbVar9 + 1;
            *(uint *)(rctx + 0x14) = uVar11 << 8;
            uVar11 = uVar11 << 8 | (uint)*pbVar9;
            *(uint *)(rctx + 0x14) = uVar11;
            pbVar9 = local_30;
          } while (local_30 != pbVar14 + uVar12);
          if (0x19000 < uVar11) goto LAB_000dfbd4;
          *(uint *)(rctx + 0x14) = uVar11 + uVar12 + 2;
        }
        *(undefined4 *)rctx = 4;
        goto LAB_000dfa70;
      }
      while ((sVar2 = BIO_ctrl(*(BIO **)(rctx + 0x10),3,0,&local_30), 0 < (int)sVar2 &&
             (pvVar3 = memchr(local_30,10,sVar2), pvVar3 != (void *)0x0))) {
        iVar7 = BIO_gets(*(BIO **)(rctx + 0x10),*(char **)(rctx + 4),*(int *)(rctx + 8));
        if (iVar7 < 1) {
          iVar7 = BIO_test_flags(*(BIO **)(rctx + 0x10),8);
          pbVar9 = local_30;
          if (iVar7 != 0) goto LAB_000dfa84;
          goto LAB_000dfbd4;
        }
        if (*(int *)(rctx + 8) == iVar7) goto LAB_000dfbd4;
        pbVar9 = *(byte **)(rctx + 4);
        if (*(int *)rctx == 1) {
          uVar12 = (uint)*pbVar9;
          if (uVar12 == 0) {
LAB_000dfc04:
            iVar7 = 0xca;
LAB_000dfc9c:
            ERR_put_error(0x27,0x76,0x73,"ocsp_ht.c",iVar7);
            *(undefined4 *)rctx = 0x1000;
            return 0;
          }
          ppuVar5 = __ctype_b_loc();
          puVar10 = *ppuVar5;
          while (-1 < (int)((uint)puVar10[uVar12] << 0x12)) {
            pbVar9 = pbVar9 + 1;
            uVar12 = (uint)*pbVar9;
            if (uVar12 == 0) goto LAB_000dfc04;
          }
          bVar1 = *pbVar9;
          while( true ) {
            if (bVar1 == 0) {
              iVar7 = 0xd3;
              goto LAB_000dfc9c;
            }
            if (-1 < (int)((uint)puVar10[bVar1] << 0x12)) break;
            pbVar9 = pbVar9 + 1;
            bVar1 = *pbVar9;
          }
          bVar1 = *pbVar9;
          pbVar14 = pbVar9;
          while( true ) {
            if (bVar1 == 0) {
              iVar7 = 0xdc;
              goto LAB_000dfc9c;
            }
            if ((int)((uint)puVar10[bVar1] << 0x12) < 0) break;
            pbVar14 = pbVar14 + 1;
            bVar1 = *pbVar14;
          }
          *pbVar14 = 0;
          uVar4 = strtoul((char *)pbVar9,(char **)local_2c,10);
          if (*local_2c[0] != 0) goto LAB_000dfbd4;
          uVar12 = (uint)pbVar14[1];
          pbVar14 = pbVar14 + 1;
          if (uVar12 != 0) {
            puVar10 = *ppuVar5;
LAB_000dfb46:
            if ((int)((uint)puVar10[uVar12] << 0x12) < 0) goto LAB_000dfb40;
            sVar2 = strlen((char *)pbVar14);
            local_2c[0] = pbVar14 + (sVar2 - 1);
            while ((int)((uint)puVar10[*local_2c[0]] << 0x12) < 0) {
              *local_2c[0] = 0;
              puVar10 = *ppuVar5;
              local_2c[0] = local_2c[0] + -1;
            }
          }
LAB_000dfb8a:
          if (uVar4 != 200) {
            ERR_put_error(0x27,0x76,0x72,"ocsp_ht.c",0xf7);
            if (*pbVar14 == 0) {
              ERR_add_error_data(2,"Code=",pbVar9);
            }
            else {
              ERR_add_error_data(4,"Code=",pbVar9,",Reason=",pbVar14);
            }
            goto LAB_000dfbd4;
          }
          *(undefined4 *)rctx = 2;
        }
        else {
          bVar1 = *pbVar9;
          local_30 = pbVar9;
          while( true ) {
            if (bVar1 == 0) {
              *(undefined4 *)rctx = 3;
              goto LAB_000dfa40;
            }
            if (bVar1 != 10 && bVar1 != 0xd) break;
            bVar1 = local_30[1];
            local_30 = local_30 + 1;
          }
        }
      }
      if (*(int *)(rctx + 8) <= (int)sVar2) goto LAB_000dfbd4;
      uVar12 = *(uint *)rctx;
      goto joined_r0x000dfa0a;
    }
    if (uVar12 != 0x1007) {
      if (uVar12 == 0x1008) {
        return 1;
      }
      if (uVar12 != 0x1006) {
        return 0;
      }
      lVar6 = BIO_ctrl(*(BIO **)(rctx + 0x10),3,0,&local_30);
      iVar7 = BIO_write(*(BIO **)(rctx + 0xc),local_30 + (lVar6 - *(int *)(rctx + 0x14)),
                        *(int *)(rctx + 0x14));
      if (iVar7 < 1) {
LAB_000dfd48:
        iVar7 = BIO_test_flags(*(BIO **)(rctx + 0xc),8);
        if (iVar7 != 0) {
          return -1;
        }
LAB_000dfbd4:
        *(undefined4 *)rctx = 0x1000;
        return 0;
      }
      iVar13 = *(int *)(rctx + 0x14);
      *(int *)(rctx + 0x14) = iVar13 - iVar7;
      pbVar9 = local_30;
      if (iVar13 - iVar7 != 0) goto LAB_000dfa84;
      *(undefined4 *)rctx = 0x1007;
      BIO_ctrl(*(BIO **)(rctx + 0x10),1,0,(void *)0x0);
    }
    lVar6 = BIO_ctrl(*(BIO **)(rctx + 0xc),0xb,0,(void *)0x0);
    if (lVar6 < 1) goto LAB_000dfd48;
    *(undefined4 *)rctx = 1;
    uVar12 = 1;
  } while( true );
LAB_000dfb40:
  pbVar14 = pbVar14 + 1;
  uVar12 = (uint)*pbVar14;
  if (uVar12 == 0) goto LAB_000dfb8a;
  goto LAB_000dfb46;
}

