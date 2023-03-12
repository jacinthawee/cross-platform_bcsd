
undefined4 ssl3_send_server_hello(undefined4 *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined uVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  
  if (param_1[0xd] == 0x2130) {
    puVar2 = *(undefined **)(param_1[0xf] + 4);
    puVar2[4] = (char)((uint)*param_1 >> 8);
    puVar2[5] = (char)*param_1;
    iVar5 = param_1[0x16];
    *(undefined4 *)(puVar2 + 6) = *(undefined4 *)(iVar5 + 0xa0);
    *(undefined4 *)(puVar2 + 10) = *(undefined4 *)(iVar5 + 0xa4);
    *(undefined4 *)(puVar2 + 0xe) = *(undefined4 *)(iVar5 + 0xa8);
    *(undefined4 *)(puVar2 + 0x12) = *(undefined4 *)(iVar5 + 0xac);
    *(undefined4 *)(puVar2 + 0x16) = *(undefined4 *)(iVar5 + 0xb0);
    *(undefined4 *)(puVar2 + 0x1a) = *(undefined4 *)(iVar5 + 0xb4);
    *(undefined4 *)(puVar2 + 0x1e) = *(undefined4 *)(iVar5 + 0xb8);
    *(undefined4 *)(puVar2 + 0x22) = *(undefined4 *)(iVar5 + 0xbc);
    if (((*(byte *)(param_1[0x39] + 0x20) & 2) == 0) && (param_1[0x1b] == 0)) {
      uVar7 = 0;
      *(undefined4 *)(param_1[0x30] + 0x44) = 0;
      uVar4 = 0;
LAB_080998c2:
      puVar2[0x26] = uVar7;
      iVar5 = param_1[0x30];
      if (uVar4 < 4) {
        if ((uVar4 != 0) && (puVar2[0x27] = *(undefined *)(iVar5 + 0x48), (uVar4 & 2) != 0)) {
          *(undefined2 *)(puVar2 + uVar4 + 0x25) = *(undefined2 *)(iVar5 + 0x46 + uVar4);
        }
      }
      else {
        *(undefined4 *)(puVar2 + 0x27) = *(undefined4 *)(iVar5 + 0x48);
        *(undefined4 *)(puVar2 + uVar4 + 0x23) = *(undefined4 *)(iVar5 + 0x44 + uVar4);
        uVar9 = (uint)(puVar2 + (0x27 - ((uint)(puVar2 + 0x2b) & 0xfffffffc)) + uVar4) & 0xfffffffc;
        if (3 < uVar9) {
          uVar10 = 0;
          do {
            *(undefined4 *)(((uint)(puVar2 + 0x2b) & 0xfffffffc) + uVar10) =
                 *(undefined4 *)
                  (((iVar5 + 0x48) - (int)(puVar2 + (0x27 - ((uint)(puVar2 + 0x2b) & 0xfffffffc))))
                  + uVar10);
            uVar10 = uVar10 + 4;
          } while (uVar10 < uVar9);
        }
      }
      puVar1 = puVar2 + uVar4 + 0x27;
      iVar5 = ssl3_put_cipher_by_char(*(undefined4 *)(param_1[0x16] + 0x344),puVar1);
      pbVar8 = *(byte **)(param_1[0x16] + 0x38c);
      if (pbVar8 != (byte *)0x0) {
        pbVar8 = (byte *)(uint)*pbVar8;
      }
      puVar1[iVar5] = (char)pbVar8;
      iVar6 = ssl_prepare_serverhello_tlsext(param_1);
      if (iVar6 < 1) {
        iVar6 = 0x5dc;
        iVar5 = 0x113;
      }
      else {
        iVar5 = ssl_add_serverhello_tlsext(param_1,puVar1 + iVar5 + 1,puVar2 + 0x4000);
        if (iVar5 != 0) {
          iVar6 = iVar5 - (int)(puVar2 + 4);
          *puVar2 = 2;
          puVar2[3] = (char)iVar6;
          puVar2[1] = (char)((uint)iVar6 >> 0x10);
          puVar2[2] = (char)((uint)iVar6 >> 8);
          param_1[0xd] = 0x2131;
          param_1[0x11] = iVar5 - (int)puVar2;
          param_1[0x12] = 0;
          goto LAB_08099824;
        }
        iVar6 = 0x5e1;
        iVar5 = 0x44;
      }
    }
    else {
      uVar4 = *(uint *)(param_1[0x30] + 0x44);
      uVar7 = (undefined)uVar4;
      if ((int)uVar4 < 0x21) goto LAB_080998c2;
      iVar6 = 0x5c5;
      iVar5 = 0x44;
    }
    ERR_put_error(0x14,0xf2,iVar5,"s3_srvr.c",iVar6);
    uVar3 = 0xffffffff;
  }
  else {
LAB_08099824:
    uVar3 = ssl3_do_write(param_1,0x16);
  }
  return uVar3;
}

