
int asn1_GetSequence(ASN1_const_CTX *c,long *length)

{
  byte bVar1;
  byte *pbVar2;
  uchar *puVar3;
  ushort uVar4;
  uint3 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  byte *local_28;
  byte *local_24;
  uint local_20;
  
  iVar7 = *length;
  if (iVar7 != 0) {
    pbVar2 = c->p;
    bVar9 = *pbVar2;
    uVar6 = bVar9 & 0x1f;
    if ((char)uVar6 == '\x1f') {
      iVar8 = iVar7 + -1;
      if (iVar8 != 0) {
        uVar6 = 0;
        local_28 = pbVar2;
        while( true ) {
          bVar1 = local_28[1];
          if (-1 < (char)bVar1) break;
          uVar6 = uVar6 << 7 | bVar1 & 0x7f;
          iVar8 = iVar8 + -1;
          if ((0xffffff < (int)uVar6) || (local_28 = local_28 + 1, iVar8 == 0)) goto LAB_08152ce0;
        }
        iVar8 = iVar8 + -1;
        if (iVar8 != 0) {
          local_28 = local_28 + 2;
          uVar6 = (uint)bVar1 | uVar6 << 7;
          goto LAB_08152d6a;
        }
      }
    }
    else {
      iVar8 = iVar7 + -1;
      if (iVar8 != 0) {
        local_28 = pbVar2 + 1;
LAB_08152d6a:
        c->tag = uVar6;
        c->xclass = bVar9 & 0xc0;
        if (0 < iVar8) {
          bVar1 = *local_28;
          if (bVar1 == 0x80) {
            uVar6 = 1;
            local_24 = local_28 + 1;
            local_20 = 0;
LAB_08152dc0:
            c->slen = local_20;
            bVar9 = bVar9 & 0x20;
            if (iVar7 - ((int)local_24 - (int)pbVar2) < (int)local_20) {
              ERR_put_error(0xd,0x72,0x9b,"asn1_lib.c",0x8e);
              bVar9 = bVar9 | 0x80;
            }
            uVar6 = uVar6 | bVar9;
            c->inf = uVar6;
            c->p = local_24;
            if ((bVar9 & 0x80) == 0) {
              if (c->tag != 0x10) {
                c->error = 0x3d;
                return 0;
              }
              puVar3 = c->max;
              iVar7 = *length - ((int)local_24 - (int)pbVar2);
              *length = iVar7;
              if ((puVar3 != (uchar *)0x0) && (iVar7 < 0)) {
                c->error = 0x3e;
                return bVar9 & 0x80;
              }
              if (uVar6 == 0x21) {
                c->slen = (long)(*c->pp + (iVar7 - (int)local_24));
              }
              c->eos = 0;
              return 1;
            }
            goto LAB_08152d02;
          }
          uVar6 = bVar1 & 0x7f;
          local_24 = local_28 + 1;
          local_20 = uVar6;
          if (-1 < (char)bVar1) goto LAB_08152dae;
          if (((byte)uVar6 < 5) && (iVar8 != 1)) {
            if ((byte)uVar6 == 0) {
              uVar6 = 0;
              local_20 = 0;
              goto LAB_08152dc0;
            }
            local_24 = local_28 + 2;
            local_20 = (uint)local_28[1];
            if (iVar8 != 2) {
              if (uVar6 != 1) {
                local_24 = local_28 + 3;
                uVar4 = CONCAT11(local_28[1],local_28[2]);
                local_20 = (uint)uVar4;
                if (iVar8 == 3) goto LAB_08152ce0;
                if (uVar6 != 2) {
                  local_24 = local_28 + 4;
                  uVar5 = CONCAT21(uVar4,local_28[3]);
                  local_20 = (uint)uVar5;
                  if (iVar8 == 4) goto LAB_08152ce0;
                  if (uVar6 != 3) {
                    local_24 = local_28 + 5;
                    local_20 = CONCAT31(uVar5,local_28[4]);
                    if ((iVar8 == 5) || (uVar6 != 4)) goto LAB_08152ce0;
                  }
                }
              }
LAB_08152dae:
              if (-1 < (int)local_20) {
                uVar6 = 0;
                goto LAB_08152dc0;
              }
            }
          }
        }
      }
    }
  }
LAB_08152ce0:
  ERR_put_error(0xd,0x72,0x7b,"asn1_lib.c",0x96);
  c->inf = 0x80;
LAB_08152d02:
  c->error = 0x3c;
  return 0;
}

