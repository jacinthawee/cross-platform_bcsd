
int i2c_ASN1_BIT_STRING(ASN1_BIT_STRING *a,uchar **pp)

{
  uchar *puVar1;
  uchar *puVar2;
  byte bVar3;
  byte *pbVar4;
  byte bVar5;
  uint uVar6;
  uint __n;
  int iVar7;
  byte local_24;
  size_t local_20;
  
  if (a == (ASN1_BIT_STRING *)0x0) {
    return 0;
  }
  __n = a->length;
  if ((int)__n < 1) {
    iVar7 = __n + 1;
    if (pp == (uchar **)0x0) {
      return iVar7;
    }
    puVar1 = *pp;
    *puVar1 = '\0';
    puVar2 = a->data;
    if (__n != 0) {
      uVar6 = 0;
      do {
        puVar1[uVar6 + 1] = puVar2[uVar6];
        uVar6 = uVar6 + 1;
      } while (uVar6 < __n);
    }
    pbVar4 = puVar1 + __n + 1;
  }
  else {
    if ((a->flags & 8U) == 0) {
      do {
        bVar5 = a->data[__n - 1];
        if (bVar5 != 0) {
          iVar7 = __n + 1;
          local_20 = __n;
          goto LAB_08138ffb;
        }
        __n = __n - 1;
      } while (__n != 0);
      bVar5 = a->data[-1];
      iVar7 = 1;
      local_20 = 0;
LAB_08138ffb:
      if ((bVar5 & 1) == 0) {
        if ((bVar5 & 2) == 0) {
          if ((bVar5 & 4) == 0) {
            if ((bVar5 & 8) == 0) {
              if ((bVar5 & 0x10) == 0) {
                if ((bVar5 & 0x20) == 0) {
                  if ((bVar5 & 0x40) == 0) {
                    bVar3 = bVar5 & 0x80;
                    local_24 = 0xff;
                    if ((bVar5 & 0x80) != 0) {
                      local_24 = 0x80;
                      bVar3 = 7;
                    }
                  }
                  else {
                    local_24 = 0xc0;
                    bVar3 = 6;
                  }
                }
                else {
                  local_24 = 0xe0;
                  bVar3 = 5;
                }
              }
              else {
                local_24 = 0xf0;
                bVar3 = 4;
              }
            }
            else {
              local_24 = 0xf8;
              bVar3 = 3;
            }
          }
          else {
            local_24 = 0xfc;
            bVar3 = 2;
          }
        }
        else {
          local_24 = 0xfe;
          bVar3 = 1;
        }
      }
      else {
        local_24 = 0xff;
        bVar3 = 0;
      }
      if (pp == (uchar **)0x0) {
        return iVar7;
      }
      pbVar4 = *pp + 1;
      **pp = bVar3;
      memcpy(pbVar4,a->data,local_20);
      pbVar4 = pbVar4 + local_20;
      if (__n == 0) goto LAB_08138fbf;
    }
    else {
      iVar7 = __n + 1;
      bVar5 = (byte)a->flags & 7;
      if (pp == (uchar **)0x0) {
        return iVar7;
      }
      pbVar4 = *pp + 1;
      **pp = bVar5;
      memcpy(pbVar4,a->data,__n);
      pbVar4 = pbVar4 + __n;
      local_24 = (byte)(0xff << bVar5);
    }
    pbVar4[-1] = pbVar4[-1] & local_24;
  }
LAB_08138fbf:
  *pp = pbVar4;
  return iVar7;
}

