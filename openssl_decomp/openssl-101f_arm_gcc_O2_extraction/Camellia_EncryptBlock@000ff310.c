
void Camellia_EncryptBlock(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0x80) {
    uVar1 = 3;
  }
  else {
    uVar1 = 4;
  }
  Camellia_EncryptBlock_Rounds(uVar1);
  return;
}
