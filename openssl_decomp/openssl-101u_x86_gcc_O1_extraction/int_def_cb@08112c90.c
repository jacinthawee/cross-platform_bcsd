
undefined4 int_def_cb(byte *param_1,int param_2,uint *param_3)

{
  undefined4 uVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  
  if (param_1 == (byte *)0x0) {
    return 0;
  }
  iVar2 = 4;
  if (param_2 < 5) {
    iVar2 = param_2;
  }
  bVar5 = false;
  bVar6 = true;
  pbVar3 = param_1;
  pbVar4 = (byte *)0x8200671;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pbVar3 < *pbVar4;
    bVar6 = *pbVar3 == *pbVar4;
    pbVar3 = pbVar3 + 1;
    pbVar4 = pbVar4 + 1;
  } while (bVar6);
  if ((!bVar5 && !bVar6) == bVar5) {
    *param_3 = *param_3 | 0xffff;
    uVar1 = 1;
  }
  else {
    iVar2 = 4;
    if (param_2 < 5) {
      iVar2 = param_2;
    }
    bVar5 = true;
    pbVar3 = param_1;
    pbVar4 = (byte *)0x82229a8;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + 1;
      pbVar4 = pbVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      *param_3 = *param_3 | 1;
      return 1;
    }
    iVar2 = 4;
    if (param_2 < 5) {
      iVar2 = param_2;
    }
    bVar5 = true;
    pbVar3 = param_1;
    pbVar4 = &DAT_0820054c;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + 1;
      pbVar4 = pbVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      *param_3 = *param_3 | 2;
      return 1;
    }
    iVar2 = 5;
    if (param_2 < 6) {
      iVar2 = param_2;
    }
    bVar5 = false;
    bVar6 = true;
    pbVar3 = param_1;
    pbVar4 = &DAT_0820071e;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pbVar3 < *pbVar4;
      bVar6 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + 1;
      pbVar4 = pbVar4 + 1;
    } while (bVar6);
    if ((!bVar5 && !bVar6) == bVar5) {
      *param_3 = *param_3 | 0x10;
      uVar1 = 1;
    }
    else {
      iVar2 = 6;
      if (param_2 < 7) {
        iVar2 = param_2;
      }
      bVar5 = true;
      pbVar3 = param_1;
      pbVar4 = &DAT_0820054a;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pbVar3 == *pbVar4;
        pbVar3 = pbVar3 + 1;
        pbVar4 = pbVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        *param_3 = *param_3 | 0x20;
        uVar1 = 1;
      }
      else {
        iVar2 = 3;
        if (param_2 < 4) {
          iVar2 = param_2;
        }
        bVar5 = true;
        pbVar3 = param_1;
        pbVar4 = (byte *)0x82098fa;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar5 = *pbVar3 == *pbVar4;
          pbVar3 = pbVar3 + 1;
          pbVar4 = pbVar4 + 1;
        } while (bVar5);
        if (bVar5) {
          *param_3 = *param_3 | 4;
          uVar1 = 1;
        }
        else {
          iVar2 = 5;
          if (param_2 < 6) {
            iVar2 = param_2;
          }
          bVar5 = true;
          pbVar3 = param_1;
          pbVar4 = (byte *)0x8237846;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar5 = *pbVar3 == *pbVar4;
            pbVar3 = pbVar3 + 1;
            pbVar4 = pbVar4 + 1;
          } while (bVar5);
          if (bVar5) {
            *param_3 = *param_3 | 8;
            uVar1 = 1;
          }
          else {
            iVar2 = 8;
            if (param_2 < 9) {
              iVar2 = param_2;
            }
            bVar5 = false;
            bVar6 = true;
            pbVar3 = param_1;
            pbVar4 = (byte *)"CIPHERS";
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar5 = *pbVar3 < *pbVar4;
              bVar6 = *pbVar3 == *pbVar4;
              pbVar3 = pbVar3 + 1;
              pbVar4 = pbVar4 + 1;
            } while (bVar6);
            if ((!bVar5 && !bVar6) == bVar5) {
              *param_3 = *param_3 | 0x40;
              uVar1 = 1;
            }
            else {
              iVar2 = 8;
              if (param_2 < 9) {
                iVar2 = param_2;
              }
              bVar5 = true;
              pbVar3 = param_1;
              pbVar4 = (byte *)"DIGESTS";
              do {
                if (iVar2 == 0) break;
                iVar2 = iVar2 + -1;
                bVar5 = *pbVar3 == *pbVar4;
                pbVar3 = pbVar3 + 1;
                pbVar4 = pbVar4 + 1;
              } while (bVar5);
              if (bVar5) {
                *param_3 = *param_3 | 0x80;
                uVar1 = 1;
              }
              else {
                iVar2 = 5;
                if (param_2 < 6) {
                  iVar2 = param_2;
                }
                bVar5 = true;
                pbVar3 = param_1;
                pbVar4 = &DAT_082265f9;
                do {
                  if (iVar2 == 0) break;
                  iVar2 = iVar2 + -1;
                  bVar5 = *pbVar3 == *pbVar4;
                  pbVar3 = pbVar3 + 1;
                  pbVar4 = pbVar4 + 1;
                } while (bVar5);
                if (bVar5) {
                  *param_3 = *param_3 | 0x600;
                  uVar1 = 1;
                }
                else {
                  iVar2 = 0xc;
                  if (param_2 < 0xd) {
                    iVar2 = param_2;
                  }
                  bVar5 = true;
                  pbVar3 = param_1;
                  pbVar4 = (byte *)"PKEY_CRYPTO";
                  do {
                    if (iVar2 == 0) break;
                    iVar2 = iVar2 + -1;
                    bVar5 = *pbVar3 == *pbVar4;
                    pbVar3 = pbVar3 + 1;
                    pbVar4 = pbVar4 + 1;
                  } while (bVar5);
                  if (bVar5) {
                    *param_3 = *param_3 | 0x200;
                    uVar1 = 1;
                  }
                  else {
                    iVar2 = 10;
                    if (param_2 < 0xb) {
                      iVar2 = param_2;
                    }
                    bVar5 = false;
                    bVar6 = true;
                    pbVar3 = (byte *)"PKEY_ASN1";
                    do {
                      if (iVar2 == 0) break;
                      iVar2 = iVar2 + -1;
                      bVar5 = *param_1 < *pbVar3;
                      bVar6 = *param_1 == *pbVar3;
                      param_1 = param_1 + 1;
                      pbVar3 = pbVar3 + 1;
                    } while (bVar6);
                    uVar1 = 0;
                    if ((!bVar5 && !bVar6) == bVar5) {
                      *param_3 = *param_3 | 0x400;
                      uVar1 = 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar1;
}
