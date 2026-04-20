Import("env")

def upload_dummy(source, target, env):
    print("Uploading dummy firmware...")
    env.Execute("pio run -e dummy -t upload")

env.AddPreAction("test", upload_dummy)
