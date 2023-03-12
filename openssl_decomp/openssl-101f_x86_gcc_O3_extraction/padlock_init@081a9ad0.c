
bool padlock_init(void)

{
  return padlock_use_rng != 0 || padlock_use_ace != 0;
}

