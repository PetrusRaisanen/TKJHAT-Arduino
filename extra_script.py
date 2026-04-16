import time

Import("env")

def after_upload(source, target, env):
    print("Delay after uploading...")
    import time
    time.sleep(3)
    print("Done!")

env.AddPostAction("upload", after_upload)