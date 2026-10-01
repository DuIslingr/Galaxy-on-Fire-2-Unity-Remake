# Makes the Discord Rich Presence art assets (1024 x 1024, Discord's recommended size, 512 minimum) for the application
# "Galaxy on Fire 2 Unity Remake" (1555054317155647571, uploaded under Rich Presence > Art Assets; the file name is the
# asset key DiscordPresence uses): the three campaign cards, the logo and the race emblems.
#   python Reference/tools/discord/make_assets.py   ->  Build/discord_assets/*.png
import os
from PIL import Image

root = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', '..', 'Assets')
out = os.path.join(root, '..', 'Build', 'discord_assets')
os.makedirs(out, exist_ok=True)

def card(src, key):
    im = Image.open(os.path.join(root, src)).convert('RGBA'); w, h = im.size
    sq = im.crop((0, (h - w) // 2, w, (h - w) // 2 + w)).resize((1024, 1024), Image.LANCZOS)
    bg = Image.new('RGBA', (1024, 1024), (0, 0, 0, 255)); bg.alpha_composite(sq); bg.convert('RGB').save(os.path.join(out, key + '.png'))

card('UI/MainMenu/Images/card_gof2.png', 'gof2')
card('UI/MainMenu/Images/card_valkyrie.png', 'valkyrie')
card('UI/MainMenu/Images/card_supernova.png', 'supernova')
lg = Image.open(os.path.join(root, 'UI/MainMenu/Images/logo_gof2.png')).convert('RGBA')
lg = lg.resize((900, int(lg.height * 900 / lg.width)), Image.LANCZOS)
bg = Image.new('RGBA', (1024, 1024), (4, 10, 18, 255)); bg.alpha_composite(lg, ((1024 - lg.width) // 2, (1024 - lg.height) // 2))
bg.convert('RGB').save(os.path.join(out, 'logo.png'))
for src, key in {'logo_0': 'race_terran', 'logo_1': 'race_vossk', 'logo_2': 'race_nivelian', 'logo_3': 'race_midorian',
                 'race_8': 'race_pirate', 'race_9': 'race_void'}.items():
    im = Image.open(os.path.join(root, 'Resources/GoF2Hud/%s.png' % src)).convert('RGBA')
    s = 880 / max(im.size); im = im.resize((max(1, int(im.width * s)), max(1, int(im.height * s))), Image.LANCZOS)
    bg = Image.new('RGBA', (1024, 1024), (0, 0, 0, 0)); bg.alpha_composite(im, ((1024 - im.width) // 2, (1024 - im.height) // 2))
    bg.save(os.path.join(out, key + '.png'))
