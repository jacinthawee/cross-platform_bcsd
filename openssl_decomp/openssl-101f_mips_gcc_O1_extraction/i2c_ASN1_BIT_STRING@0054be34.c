
int i2c_ASN1_BIT_STRING(ASN1_BIT_STRING *a,uchar **pp)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uchar *puVar4;
  byte bVar5;
  undefined4 in_a3;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  int iVar10;
  
  puVar1 = PTR_memcpy_006aabf4;
  if (a == (ASN1_BIT_STRING *)0x0) {
    return 0;
  }
  iVar7 = a->length;
  if (iVar7 < 1) {
    iVar10 = iVar7 + 1;
    if (pp == (uchar **)0x0) {
      return iVar10;
    }
    puVar4 = *pp;
    *puVar4 = '\0';
    iVar2 = (*(code *)puVar1)(puVar4 + 1,a->data,iVar7,in_a3,&_gp);
    puVar4 = (uchar *)(iVar2 + iVar7);
  }
  else {
    uVar8 = a->flags & 7;
    if ((a->flags & 8U) == 0) {
      puVar4 = a->data + iVar7;
      do {
        bVar5 = puVar4[-1];
        puVar4 = puVar4 + -1;
        if (bVar5 != 0) {
          iVar10 = iVar7 + 1;
          iVar2 = iVar7;
          goto LAB_0054bf14;
        }
        iVar7 = iVar7 + -1;
        iVar10 = 1;
      } while (iVar7 != 0);
      bVar5 = a->data[-1];
      iVar2 = 0;
LAB_0054bf14:
      bVar9 = 0xff;
      if ((bVar5 & 1) == 0) {
        bVar9 = 0xfe;
        if ((bVar5 & 2) == 0) {
          bVar9 = 0xfc;
          if ((bVar5 & 4) == 0) {
            bVar9 = 0xf8;
            if ((bVar5 & 8) == 0) {
              bVar9 = 0xf0;
              if ((bVar5 & 0x10) == 0) {
                bVar9 = 0xe0;
                if ((bVar5 & 0x20) == 0) {
                  bVar9 = 0xc0;
                  if ((bVar5 & 0x40) == 0) {
                    bVar5 = bVar5 & 0x80;
                    bVar9 = 0xff;
                    if (bVar5 != 0) {
                      bVar9 = 0x80;
                      bVar5 = 7;
                    }
                  }
                  else {
                    bVar5 = 6;
                  }
                }
                else {
                  bVar5 = 5;
                }
              }
              else {
                bVar5 = 4;
              }
            }
            else {
              bVar5 = 3;
            }
          }
          else {
            bVar5 = 2;
          }
        }
        else {
          bVar5 = 1;
        }
      }
      else {
        bVar5 = 0;
      }
      if (pp == (uchar **)0x0) {
        return iVar10;
      }
      pbVar6 = *pp;
      *pbVar6 = bVar5;
      iVar3 = (*(code *)puVar1)(pbVar6 + 1,a->data,iVar2);
      puVar4 = (uchar *)(iVar3 + iVar2);
      if (iVar7 == 0) goto LAB_0054bec4;
    }
    else {
      iVar10 = iVar7 + 1;
      if (pp == (uchar **)0x0) {
        return iVar10;
      }
      puVar4 = *pp;
      *puVar4 = (uchar)uVar8;
      iVar2 = (*(code *)puVar1)(puVar4 + 1,a->data,iVar7);
      puVar4 = (uchar *)(iVar2 + iVar7);
      bVar9 = (byte)(0xff << uVar8);
    }
    puVar4[-1] = bVar9 & puVar4[-1];
  }
LAB_0054bec4:
  *pp = puVar4;
  return iVar10;
}

